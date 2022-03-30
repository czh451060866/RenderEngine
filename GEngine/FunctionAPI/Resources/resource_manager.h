//
// Created by zhanghong50 on 2022/1/20.
//

#ifndef MYENGINE_RESOURCE_MANAGER_H
#define MYENGINE_RESOURCE_MANAGER_H

// FunctionAPI
#include "resource_predeclare.h"
#include "Resources/Mesh/instance_mesh.h"
#include "Mesh/mesh_manager.h"
#include "Shaders/shader_manager.h"
#include "Attribute/attribute_manager.h"
#include "Texture/texture_manager.h"
#include "Model/model_manager.h"
#include "FileSystem/file_handler.h" // UserAPI

GENG_BEGIN

class ResourceManager: public RenderSystem{
public:
    ResourceManager();
    ~ResourceManager();

    void insertMesh(const std::string & name, const MeshType & type);    // mesh
    void insertLight(const std::string & name, const LightType & type = DIRECTIONAL_LIGHT); // with default light
    void insertCamera(const std::string & name, const CameraType & type = PINHOLE_CAMERA); // with default camera
    void insertModel(const std::string & name, const std::string & path); // insert model 

    void setWindowSize(uint32_t width, uint32_t height);
    
    void loadShaderFromDir();
    void loadTextureFromDir();  // load texture one by one
    void loadBundleTextureFromDir(const std::string & dir, TextureType type = ColorTexture); // load Bundle Texture

    const std::vector<std::string> & getEffectNames();
    const std::vector<std::string> & getTexture2DNames();
    const std::vector<std::string> & getTexture3DNames();
    const std::string & getCurrentCamera();
    
    std::shared_ptr<InstanceMesh> queryModel(const std::string & name); 
    std::shared_ptr<InstanceMesh> queryMesh(const MeshType & type);   
    std::shared_ptr<ObjectAttribute> queryObjectAttribute(const std::string & name);


    virtual void getRenderParam(std::shared_ptr<RenderNode> & node, std::shared_ptr<RenderParam> & param) override;
    virtual std::shared_ptr<RenderMesh> getRenderMesh(std::shared_ptr<RenderNode> & node) override;
protected:

    std::unique_ptr<ModelManager> model_manager_;
    std::unique_ptr<MeshManager> mesh_manager_;
    std::unique_ptr<ShaderManager> shader_manager_;
    std::unique_ptr<AttributeManager> attribute_manager_;
    std::unique_ptr<TextureManager> texture_manager_;
    std::unique_ptr<FileHandler> file_handler_;

    std::vector<std::string> cameras_; // save al the cameras
    std::vector<std::string> lights_;   // save all the lights 

    uint32_t cur_camera_id_ = -1;
    uint32_t window_h_ = 1000;
    uint32_t window_w_ = 1000;
};

GENG_END

#endif //MYENGINE_RESOURCE_MANAGER_H
