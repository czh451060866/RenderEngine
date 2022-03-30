//
// Created by HongZh on 2022/02/20, 23:48:04
//

#include "sphere_obj.h"

GENG_BEGIN

SphereObject::SphereObject(){
    radius_ = 1.0f;
    stack_range_ = M_PI / 2.0f;
    sector_range_ = 2.0f * M_PI ;
    num_sector_ = 50;
    num_stack_ = 50;
}

SphereObject::~SphereObject(){

}

void SphereObject::generateMesh(){
    if(is_generated_){
        return;
    }
    // 生成球形网格
    float stack_step = stack_range_ * 2 / num_stack_; // 每一个stack的横跨的角度
    float sector_step = sector_range_ / num_sector_; //每个sector的横跨角度
    float fai;
    float theta;

    for(int i = 0; i <= num_stack_; i++){
        fai = stack_range_  - (float) i * stack_step;

        // 顶点序号
        int k1 = i * (num_sector_ + 1);
        int k2 = k1 + num_sector_ + 1;

        for(int j = 0; j <= num_sector_; j++, k1++, k2++){
            theta = j * sector_step;
            // vertices
            float z = radius_ * cos(fai) * cos(theta);
            float x = radius_ * cos(fai) * sin(theta);
            float y = radius_ * sin(fai);

            vertices_.push_back(x);
            vertices_.push_back(y);
            vertices_.push_back(z);

            // normal vectors
            float nx = x * 1.0f / radius_;
            float ny = y * 1.0f / radius_;
            float nz = z * 1.0f / radius_;
            normals_.push_back(nx);
            normals_.push_back(ny);
            normals_.push_back(nz);

            // texture coord
            float s = (float) j / num_sector_;
            float t = (float) i / num_stack_;
            tex_coords_.push_back(s);
            tex_coords_.push_back(t);
            tex_coords_.push_back(-1.0f);

            // 序号
            if(i == num_stack_ || j == num_sector_){
                continue;
            }


            vert_indices_.push_back(k1);
            vert_indices_.push_back(k2);
            vert_indices_.push_back(k1 + 1);
        
            vert_indices_.push_back(k1 + 1);
            vert_indices_.push_back(k2);
            vert_indices_.push_back(k2 + 1);
        }
    }

    //  TODO
    NormalGenerator normal_generator;
    normal_generator.processTangentsSingleThread(vertices_, vert_indices_, tex_coords_);
    setTangents(normal_generator.getTangents());
    setBitangents(normal_generator.getBitangents());

    is_generated_ = true;
    mesh_t_ = PREDECLARED_SPHERE;
}


void SphereObject::setRadius(const float & r){
    radius_ = r;
}

void SphereObject::setNumOfStack(const float & n_stack){
    num_stack_ = n_stack;
}
void SphereObject::setNumOfSector(const float & n_sector){
    num_sector_ = n_sector;
}
void SphereObject::setStackRange(const float & stack_range){
    stack_range_ = stack_range;
}
void SphereObject::setSectorRange(const float & sector_range){
    sector_range_ = sector_range;
}

GENG_END