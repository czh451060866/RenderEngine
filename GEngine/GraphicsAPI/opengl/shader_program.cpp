//
// Created by zhanghong50 on 2022/1/26.
//

#include "shader_program.h"
#include "RenderLog/render_log.h"
#include "RenderModules/shader_mod.h"
#include "RenderModules/texture_mod.h"
#include "graphic_predeclared.h"

GENG_BEGIN

ShaderProgram::ShaderProgram() : unit_c_(0){
    program_id_ = -1;

    vert_shader_ = new Shader(GE_VERTEX_SHADER);
    frag_shader_ = new Shader(GE_FRAGMENT_SHADER);

    createProgram();
}

ShaderProgram::~ShaderProgram() {
    delete vert_shader_;
    delete frag_shader_;
}

void ShaderProgram::linkVertShader(const char *data, uint32_t length) {
    // generate Shader
    vert_shader_->createShader();
    vert_shader_->linkShaderSource(data, length);
    vert_shader_->compileShader();
    vert_shader_->getShaderStatus();
}

void ShaderProgram::linkFragShader(const char *data, uint32_t length) {
    frag_shader_->createShader();
    frag_shader_->linkShaderSource(data, length);
    frag_shader_->compileShader();
    frag_shader_->getShaderStatus();

}

void ShaderProgram::setUpProgram(const std::string & name) {
    name_ = name;
    attachProgram();
    linkProgram();
    getProgramStatus();
    parseUniforms();
    parseAttribs();
    vert_shader_->deleteShader();
    frag_shader_->deleteShader();
}



void ShaderProgram::createProgram() {
    program_id_ = glCreateProgram();
}

void ShaderProgram::attachProgram(){
    glAttachShader(program_id_, vert_shader_->shader_id_);
    glAttachShader(program_id_, frag_shader_->shader_id_);
}


// TODO 
// deal will all kinds of textures
void ShaderProgram::saveTextureInfo(const std::string & key){
    for(auto const & [type, prefix]: tex_prefix){
        if(key.find(prefix) != std::string::npos){
                struct AttachedTexInfo info;
                info.loc_ = getUniformLocation(key);
                info.unit_id_ = unit_c_;
                info.type_ = type;
                glUniform1i(info.loc_, unit_c_++);  // assign a texture unit 
                tex_info_[key] = std::move(info);
                break;
        } // TODO to extend
    }
}

void ShaderProgram::parseUniforms(){
    GLint i, count;
    GLint size;
    GLenum type;
    const GLsizei buf_size = 64;
    GLchar name[buf_size];
    GLsizei length;
    glGetProgramiv(program_id_, GL_ACTIVE_UNIFORMS, &count);

    for(i = 0; i < count; i++){
        glGetActiveUniform(program_id_, (GLuint)i, buf_size, &length, &size, &type, name);
        switch(type){
            case GE_SAMPLER_2D:
            case GE_SAMPLER_CUBE:{
                std::string key(name);
                saveTextureInfo(key);
            }
            default:{ //TODO
                struct VariableInfo info;
                info.loc_ = getUniformLocation(name);
                info.type_ = type;
                uniform_info_[name] = std::move(info);
                break;
            }
        }
    }
}

void ShaderProgram::parseAttribs(){
    GLint i, count;
    GLint size;
    GLenum type;
    const GLsizei buf_size = 64;
    GLchar name[buf_size];
    GLsizei length;
    glGetProgramiv(program_id_, GL_ACTIVE_ATTRIBUTES, &count);
    for(i = 0; i < count; i++){
        glGetActiveAttrib(program_id_, (GLuint)i, buf_size, &length, &size, &type, name);  // store the loc of attributes
        struct VariableInfo info;
        info.loc_ = i;
        info.type_ = type;
        attrib_info_[name] = info;
    }
}

void ShaderProgram::linkProgram() {
    glLinkProgram(program_id_);
}

void ShaderProgram::deleteProgram() {
    glDeleteProgram(program_id_);
}

void ShaderProgram::bindProgram() {
    glUseProgram(program_id_);
}

void ShaderProgram::unbindProgram() {
    glUseProgram(0);
}

void ShaderProgram::getProgramStatus() {
    GLint len_log, slen;
    // TODO
    glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &len_log);
    if(len_log > 1){
        auto compiler_log = (GLcharARB*)malloc(len_log);
        glGetProgramInfoLog(program_id_, len_log, &slen, compiler_log);
        RenderLog & render_log = RenderLog::getInstance();
        render_log.submitLog("-- Shader Program Error : \n%s\n", compiler_log);
        free(compiler_log);
    }
}

uint32_t ShaderProgram::getAttribLocation(const std::string &key) {
    if(attrib_info_.find(key) != attrib_info_.end()){
        return attrib_info_.at(key).loc_;
    }
    return glGetAttribLocation(program_id_, key.c_str());
}

uint32_t ShaderProgram::getUniformLocation(const std::string &key) {
    if(uniform_info_.find(key) != uniform_info_.end()){
        return uniform_info_.at(key).loc_;
    }
    return glGetUniformLocation(program_id_, key.c_str());
}

uint32_t ShaderProgram::getPosLocation() {
    return getAttribLocation(remain_key.at(VERTEX_POSITION));
}

uint32_t ShaderProgram::getUVLocation() {
    return getAttribLocation(remain_key.at(TEXTURE_COORDINATE));
}

uint32_t ShaderProgram::getNormLocation() {
    return getAttribLocation(remain_key.at(VERTEX_NORMAL));
}

uint32_t ShaderProgram::getTangentLocation(){
    return getAttribLocation(remain_key.at(VERTEX_TANGENT));
}

uint32_t ShaderProgram::getBitangentLocation(){
    return getAttribLocation(remain_key.at(VERTEX_BITANGENT));
}

void ShaderProgram::setUniform1f(const std::string &key, const float &val) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniform1f(loc, val);
    }
}

void ShaderProgram::setUniform1fv(const std::string &key, std::vector<float> vals) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniform1fv(loc, vals.size(), &vals[0]);
    }
}

void ShaderProgram::setUniform2f(const std::string &key, float val1, float val2) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniform2f(loc, val1, val2);
    }
}

void ShaderProgram::setUniform3f(const std::string &key, float val1, float val2, float val3) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniform3f(loc, val1, val2, val3);
    }
}

void ShaderProgram::setUniform4f(const std::string &key, float val1, float val2, float val3, float val4) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniform4f(loc, val1, val2, val3, val4);
    }
}

void ShaderProgram::setUniformMat4f(const std::string &key, const GMat4 &mat4_val) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniformMatrix4fv(loc, 1, GL_FALSE, & mat4_val[0][0]);
    }
}

void ShaderProgram::setUniformVec3(const std::string &key, const GVec3 &vec) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniform3fv(loc, 1, &vec[0]);
    }
}

void ShaderProgram::setUniform1i(const std::string &key, const GLint &val) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        glUniform1i(loc, val);
    }
}

void ShaderProgram::setUniformTexture(const std::string &key, std::shared_ptr<TextureModule> tex) {
    GLint loc = getUniformLocation(key);
    if((int) loc != -1){
        std::shared_ptr<Texture2D> tex_m = std::static_pointer_cast<Texture2D>(tex);
        tex_m->activeTexture(tex_info_.at(key).unit_id_); 
        tex_m->bindTexture();
        // glUniform1i(loc, tex_m->unit_id_);
        //tex_m->unbindTexture();
    }
}


GENG_END