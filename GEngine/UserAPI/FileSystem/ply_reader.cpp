//
// Created by HongZh on 2022/03/10, 19:22:02
//

#include "ply_reader.h"
#include "FunctionAPI/Algorithms/algo_predeclared.h"

GENG_BEGIN

PlyReader::PlyReader(){

}

PlyReader::~PlyReader(){

}

// TODO: uncompleted
void PlyReader::readPLYFile(const std::string & path, PLYInfo * ply_file){
    #ifdef DEBUG
    GTimer timer("Read PLY");
    #endif // DEBUG
    bool is_data = false;
    // PLY
    std::fstream fs;
    fs.open(path);
    if(fs.is_open()){
        std::string data;
        while(std::getline(fs, data)){
            if(!is_data){
                // get the number of vertices
                if(data.find("element vertex") != std::string::npos){
                    sscanf(data.c_str(), "element vertex %d", &ply_file->n_vertices_);
                    continue;
                }
                // get the number of vert_indices
                if(data.find("element face") != std::string::npos){
                    sscanf(data.c_str(), "element face %d", &ply_file->n_faces_);
                    continue;
                }

                if(data.find("end_header") != std::string::npos){
                    is_data = true;
                }
                
            }
            else{
                if(data.find(".") != std::string::npos){
                    float x, y, z;
                    sscanf(data.c_str(), "%f %f %f", &x, &y, &z);
                    ply_file->vertices_.push_back(x);
                    ply_file->vertices_.push_back(y);
                    ply_file->vertices_.push_back(z);
                }
                else{
                    uint32_t n, x, y, z;
                    sscanf(data.c_str(), "%d %d %d %d", &n, &x, &y, &z);
                    ply_file->indices_.push_back(x);
                    ply_file->indices_.push_back(y);
                    ply_file->indices_.push_back(z);
                }
            }
        }
    }
    fs.close();
}

GENG_END