//
// Created by HongZh on 2022/03/12, 20:41:11
//

#include "mesh_from_texture.h"

GENG_BEGIN


MeshGeneratorFromTex::MeshGeneratorFromTex():
factor_(0.5f){

}

MeshGeneratorFromTex::~MeshGeneratorFromTex(){

}

void MeshGeneratorFromTex::createMeshFromTexture(const uint32_t &width, const uint32_t &height, const uint32_t &channels, const char *buffer, bool need_normals){
    for(uint32_t i = 0; i < width; i++){
        for(uint32_t j = 0 ; j < height; j++){
            uint32_t k1 = i * height + j;
            uint32_t k2 = (i + 1) * height + j;


            float x = (float)(i) / width;
            float y = (float) buffer[i * height + j] / 255.0f;
            float z = (float)(j) / height;
            vertices_.push_back(x);
            vertices_.push_back(y);
            vertices_.push_back(z);

            if(i == width - 1 || j == height - 1) {
                continue;
            }

            if(i != width - 1){
                vert_indices_.push_back(k1);
                vert_indices_.push_back(k2);
                vert_indices_.push_back(k1 + 1);
            }

            if(j != height - 1){
                vert_indices_.push_back(k2);
                vert_indices_.push_back(k2 + 1);
                vert_indices_.push_back(k1 + 1);
            }
        }
    }
    

}

void MeshGeneratorFromTex::modifyMeshByTexture(const uint32_t &width, const uint32_t &height, const uint32_t &channels, const char *buffer,  bool need_normals){

}
GENG_END