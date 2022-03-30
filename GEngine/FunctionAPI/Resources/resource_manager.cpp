//
// Created by zhanghong50 on 2022/1/20.
//

#include "resource_manager.h"
#include "Scene/SceneTree/scene_node.h"

GENG_BEGIN

ResourceManager::ResourceManager():
mesh_manager_(std::make_unique<MeshManager>()),
shader_manager_(std::make_unique<ShaderManager>()),
attribute_manager_(std::make_unique<AttributeManager>()),
file_handler_(std::make_unique<FileHandler>()),
texture_manager_(std::make_unique<TextureManager>()),
model_manager_(std::make_unique<ModelManager>()){

    // TODO debug info
    // load Shader 
    loadShaderFromDir();

    // load texture
    loadTextureFromDir();

}

ResourceManager::~ResourceManager() {

}

void ResourceManager::insertModel(const std::string & name, const std::string & path){
    // mesh
    ModelInfo * model = nullptr;
    file_handler_->readModelFile(path, model);
    if(model)
        model_manager_->insertModel(name, model);

    // attrib 
    AttribInfo attrib_info;
    attrib_info.name = name;
    attrib_info.mesh_type_ = IMPORTED_MODEL;
    attribute_manager_->addObjectAttribute(attrib_info);
}

void ResourceManager::insertMesh(const std::string & name, const MeshType & type) {
    // mesh
    mesh_manager_->insertMesh(type);
    // attrib
    AttribInfo attrib_info;
    attrib_info.name = name;
    attrib_info.mesh_type_ = type;
    attrib_info.geo_type_ = RIDID_GEOMETRY;
    attribute_manager_->addObjectAttribute(attrib_info);
    auto obj_attrib = attribute_manager_->queryObjectAttribute(name);
}

void ResourceManager::insertCamera(const std::string & name, const CameraType & type) {
    AttribInfo attrib_info;
    attrib_info.name = name;
    attrib_info.camera_type_ = type;
    attribute_manager_->addObjectAttribute(attrib_info);

    //set camera w-h_ratio
    attribute_manager_->queryObjectAttribute(name)->setCameraRatio(float(window_w_)/(float)(window_h_));
    cameras_.push_back(name);
    cur_camera_id_ += 1;
}


void ResourceManager::insertLight(const std::string & name, const LightType & type) {
    AttribInfo attrib_info;
    attrib_info.name = name;
    attrib_info.light_type_ = type;
    attribute_manager_->addObjectAttribute(attrib_info);
}


std::shared_ptr<InstanceMesh> ResourceManager::queryMesh(const MeshType & type) {
    return mesh_manager_->accessMesh(type);
}


std::shared_ptr<InstanceMesh> ResourceManager::queryModel(const std::string & name){
    return model_manager_->queryModel(name);
}

std::shared_ptr<ObjectAttribute> ResourceManager::queryObjectAttribute(const std::string & name){
    return attribute_manager_->queryObjectAttribute(name);
}

void ResourceManager::setWindowSize(uint32_t width, uint32_t height) {
    window_w_ = width;
    window_h_ = height;
}


void ResourceManager::loadShaderFromDir(){
    file_handler_->readShaderFileList();
    for(auto const& entry: file_handler_->getShaderFileList()){
        shader_manager_->addShader(entry);
    }
}

void ResourceManager::loadTextureFromDir(){
    // TODO: exception handler
    file_handler_->readTextureList();
    for(auto const& entry: file_handler_->getTexFileList()){
        auto tex_info = texture_manager_->addTexture(entry);
        texture_manager_->loadTexture(tex_info);
    }
}

void ResourceManager::loadBundleTextureFromDir(const std::string & dir, TextureType type){
    file_handler_->readTextureList(dir);
    auto const & filelist = file_handler_->getTexFileList();
    if(filelist.empty()){
        return;
    }

    TextureInfo * info = nullptr;
    TextureInfo * head = nullptr;

    // TODO MULTIThread
    for(auto const& entry: filelist){
        if(head == nullptr){
            head = texture_manager_->addTexture(entry, type);
            info = head;
        }
        else{
            info = texture_manager_->addTexture(entry, type, info);
        }
    }
    if(head)
        texture_manager_->loadTexture(head);
}

const std::vector<std::string> & ResourceManager::getEffectNames(){
    return shader_manager_->getEffectName();
}

const std::vector<std::string> & ResourceManager::getTexture2DNames(){
    return texture_manager_->getTextureNames();
}

const std::vector<std::string> & ResourceManager::getTexture3DNames(){
    return texture_manager_->getCubeMapNames();
}

const std::string & ResourceManager::getCurrentCamera(){
    return cameras_[cur_camera_id_];
}

// get params
void ResourceManager::getRenderParam(std::shared_ptr<RenderNode> & node, std::shared_ptr<RenderParam> & param){

    // get all the attributes of node 
    const std::string & node_name = node->getNodeName();
    auto object_attrib = attribute_manager_->queryObjectAttribute(node_name);

    // geometry
    if(!object_attrib->isAttributeActivated(GEOMETRY_ATTRIB)){
        param = nullptr; 
        return;
    } // TODO

    // dynamics 
    if(object_attrib->isAttributeActivated(DYNAMICS_ATTRIB) && object_attrib->isAttributeUpdated(DYNAMICS_ATTRIB)){
        param->addParam(remain_key[MODEL_MAT], object_attrib->getTransformMat());
        param->addParam(remain_key[NORM_MAT], object_attrib->getNormalMat());
    }

    // appearance
    if(object_attrib->isAttributeActivated(APPEARANCEC_ATTRIB) && object_attrib->isAttributeUpdated(APPEARANCEC_ATTRIB)){
        param->addParam(remain_key[OBJECT_COLOR], object_attrib->getObjectColor());
        param->addParam(ColorTexture, object_attrib->getColorTexture());
        param->addParam(NormalTexture, object_attrib->getNormalTexture());
        param->addParam(CubeMapTexture, object_attrib->getCubeMap());
        // TODO: to be extended
    }

    // get current camera
    if(cur_camera_id_ < cameras_.size() && cur_camera_id_ >= 0){
        const std::string camera_name = cameras_[cur_camera_id_];
        auto camera_attrib = attribute_manager_->queryObjectAttribute(camera_name);
        if(camera_attrib){
            if(camera_attrib->isAttributeActivated(DYNAMICS_ATTRIB) &&
                camera_attrib->isAttributeActivated(CAMERA_ATTRIB) &&
                camera_attrib->isAttributeUpdated(DYNAMICS_ATTRIB)){
                param->addParam(remain_key[CAMERA_POSITION], camera_attrib->getObjectPosition());
                param->addParam(remain_key[CAMERA_PROSPECTIVE_MAT], camera_attrib->getCameraProjMat());
                param->addParam(remain_key[CAMERA_VIEW_MAT], camera_attrib->getCameraViewMat());
            }
        }
    }

    // get lighting 
    const std::string & lighting_name = node->getLightingName();
    //for() 
    auto lighting_attrib = attribute_manager_->queryObjectAttribute(lighting_name);
    if(lighting_attrib){
        if(lighting_attrib->isAttributeActivated(DYNAMICS_ATTRIB) &&
           lighting_attrib->isAttributeActivated(APPEARANCEC_ATTRIB) &&
           lighting_attrib->isAttributeUpdated(DYNAMICS_ATTRIB)){
            switch(lighting_attrib->getLightType()){
                case POINT_LIGHT:{
                    param->addParam(remain_key[LIGHT_POSITION], lighting_attrib->getObjectPosition());
                    break;
                }
                case DIRECTIONAL_LIGHT:{
                    param->addParam(remain_key[LIGHT_POSITION], lighting_attrib->getObjectPosition());
                    param->addParam(remain_key[LIGHT_DIR], lighting_attrib->getObjectFaceTo());
                    break;
                }
                default:
                    break;
            }
            param->addParam(remain_key[LIGHT_COLOR], lighting_attrib->getObjectColor());
        }
    }
 
}


std::shared_ptr<RenderMesh> ResourceManager::getRenderMesh(std::shared_ptr<RenderNode> &node){
    const MeshType & mesh_type = node->getMeshType();
    const std::string & node_name = node->getNodeName();
    switch(mesh_type){
        case IMPORTED_MODEL:{
            return model_manager_->queryModel(node_name);
        }
        case PREDECLARED_CUBE:
        case PREDECLARED_SPHERE:
        case PREDECLARED_PLANE:
        case PREDECLARED_SKYBOX:{
            return mesh_manager_->accessMesh(mesh_type);
        }
        default:
            return nullptr;
    }
}
GENG_END