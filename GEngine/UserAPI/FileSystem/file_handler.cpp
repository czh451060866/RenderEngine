//
// Created by HongZh on 2022/02/20, 15:46:25
//

#include "file_handler.h"
#include "FileSystem/file_handler_predeclared.h"

GENG_BEGIN

FileHandler::FileHandler(){

}

FileHandler::~FileHandler(){

}

const std::vector<struct ShaderFiles> & FileHandler::getShaderFileList(){
    return shader_files_;
}
const std::vector<std::string> & FileHandler::getTexFileList(){
    return texture_files_;
}

void FileHandler::setShaderFilePath(const std::string & path){
    shader_path_ = path;
}

FILE_ERROR_CODE FileHandler::readShaderFileList(){
    shader_files_.clear();
    readRecurShaderFiles(shader_path_);
    if(shader_files_.empty()){
        return ERROR_READ_FILE;
    }
    return FILE_SUCCESS;
}

FILE_ERROR_CODE FileHandler::readTextureList(){
    texture_files_.clear();
    readTextureFiles(texture_path_);
    if(texture_files_.empty()){
        return ERROR_READ_FILE;
    }
    std::sort(texture_files_.begin(), texture_files_.end());
    return FILE_SUCCESS;
}

FILE_ERROR_CODE FileHandler::readTextureList(const std::string & dir){
    texture_files_.clear();
    readTextureFiles(dir);
    if(texture_files_.empty()){
        return ERROR_READ_FILE;
    }
    std::sort(texture_files_.begin(), texture_files_.end());
    return FILE_SUCCESS;
}

void FileHandler::readRecurShaderFiles(std::string path){
    if(!std::filesystem::is_directory(path)){
        return;
    }

    struct ShaderFiles files;
    std::pair<std::string, std::pair<std::string, std::string> > shaders;
    for(const auto & entry: std::filesystem::directory_iterator(path)){
        std::string fpath = entry.path().c_str();
        if(std::filesystem::is_directory(fpath)){
            readRecurShaderFiles(entry.path());
        }
        else{
            if(fpath.find("_vert.glsl") != std::string::npos){
                files.vert_path = fpath;
            }
            else if(fpath.find("_frag.glsl") != std::string::npos){
                files.frag_path = fpath;
            }
        }
    }
    if(!files.vert_path.empty() && !files.frag_path.empty()){
        files.name = path.substr(path.find_last_of("/")+1);
        shader_files_.push_back(files);
    }
}

void FileHandler::readTextureFiles(std::string path){
    if(!std::filesystem::is_directory(path)){
        return;
    }
     for(const auto & entry: std::filesystem::directory_iterator(path)){
        std::string fpath = entry.path().c_str();
        if(std::filesystem::is_directory(fpath)){
            readTextureFiles(entry.path());
        }
        else{
            if(fpath.find(".png") != std::string::npos ||
                fpath.find(".jpg") != std::string::npos ||
                fpath.find(".jpeg") != std::string::npos){
                    texture_files_.push_back(fpath);   
                }
                
        }
    }
}

FILE_ERROR_CODE FileHandler::saveFile(int8_t * buffer, const std::string & fpath){
    return FILE_SUCCESS;
}


FILE_ERROR_CODE FileHandler::readModelFile(const std::string & path, ModelInfo * & model){
    std::filesystem::path fpath(path);
    if(std::filesystem::exists(fpath)){
        PlyReader ply_reader_;
        model = new PLYInfo();
        ply_reader_.readPLYFile(fpath, (PLYInfo*) model);
    }
    return FILE_SUCCESS;
}

GENG_END
