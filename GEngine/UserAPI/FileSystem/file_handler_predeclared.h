//
// Created by HongZh on 2022/02/20, 15:55:29
//

#ifndef MYENGINE_FILE_HANDLER_PREDECLARED_H
#define MYENGINE_FILE_HANDLER_PREDECLARED_H

#include "general_include.h"
#include <fstream>
#include <sstream> 
#include <filesystem>

GENG_BEGIN

enum FILE_ERROR_CODE{
    FILE_SUCCESS = 0,
    ERROR_WRTIE_FILE,
    ERROR_READ_FILE,
    ERROR_PATH_NOT_DIR
};

struct ShaderFiles{
    std::string name;
    std::string frag_path;
    std::string vert_path;
};

class ModelInfo{
public:
    uint32_t n_vertices_;
    uint32_t n_faces_;
    std::vector<float> vertices_;
    std::vector<uint32_t> indices_;
    ModelInfo(){

    }
    ~ModelInfo(){

    }
};


class PLYInfo: public ModelInfo{
protected:
    uint32_t n_normals_;
    std::vector<float> normals_;
public:
    PLYInfo(){

    }
    ~PLYInfo(){
        
    }
};

GENG_END

#endif //MYENGINE_FILE_HANDLER_PREDECLARED_H