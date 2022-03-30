//
// Created by HongZh on 2022/02/20, 15:13:17
//

#ifndef MYENGINE_FILE_HANDLER_H
#define MYENGINE_FILE_HANDLER_H

#include "file_handler_predeclared.h"
#include "ply_reader.h"

GENG_BEGIN

class FileHandler {
public:
    FileHandler();
    ~FileHandler();

    FILE_ERROR_CODE readModelFile(const std::string & path, ModelInfo * & model);
    FILE_ERROR_CODE readShaderFileList();
    FILE_ERROR_CODE readTextureList();
    FILE_ERROR_CODE readTextureList(const std::string & dir);
    FILE_ERROR_CODE saveFile(int8_t * buffer, const std::string & fpath);
    const std::vector<struct ShaderFiles> & getShaderFileList(); // TODO: Remove
    const std::vector<std::string> & getTexFileList();
    void setShaderFilePath(const std::string & path);

private:
    std::mutex mtx_; // TODO
    std::string shader_path_ = "../../GEngine/ResourceFile/ShaderFile/"; // TODO;
    std::string texture_path_ = "../../GEngine/ResourceFile/TextureFile/";
    std::vector<std::string> texture_files_;
    std::vector<ShaderFiles> shader_files_;
    void readRecurShaderFiles(std::string path);
    void readTextureFiles(std::string path);
};

GENG_END

#endif //MYENGINE_FILE_HANDLER_H