//
// Created by HongZh on 2022/03/11, 10:57:59
//

#include "normal_generator.h"
#include "Algorithms/Primitives/base_obj.h"
#include "Resources/Mesh/instance_mesh.h"
#include "engine_math.h"


GENG_BEGIN

NormalGenerator::NormalGenerator(){
    num_of_completed_ = 0;
}

NormalGenerator::~NormalGenerator(){

}

void NormalGenerator::processNormalsSingleThread(const std::vector<float> & vertices, const std::vector<uint32_t> & indices){
    #ifdef DEBUG
    GTimer timer("Normal Generator");
    #endif

    uint32_t num_of_vertices = vertices.size()/3;
    uint32_t offset = 3;
    uint32_t id = 0;
    
    std::vector<std::pair<GVec3, uint32_t>> norm_of_surroundings(num_of_vertices); 
    std::vector<GVec3> triangle(3);
    std::vector<uint32_t> t_id(3);    
    for(auto const & v_id : indices){
        triangle[id].x = vertices[v_id * offset];
        triangle[id].y = vertices[v_id * offset + 1];
        triangle[id].z = vertices[v_id * offset + 2];
        t_id[id] = v_id;
        if(id == 2){
            GVec3 norm = GNormalize(GCross(triangle[1] - triangle[0], triangle[2] - triangle[1]));
            for(auto const & t_i : t_id){
                norm_of_surroundings[t_i] = std::make_pair<GVec3, uint32_t>(norm + norm_of_surroundings[t_i].first, norm_of_surroundings[t_i].second + 1);
            }
            id = 0;
            continue;
        }
        id += 1;
    }

    for(auto const & [sum_norm, num]: norm_of_surroundings){
        GVec3 norm = GNormalize(sum_norm/(float)num);
        normals_.push_back(norm.x);
        normals_.push_back(norm.y);
        normals_.push_back(norm.z);
    }

}


void NormalGenerator::processTangentsSingleThread(const std::vector<float> & vertices, const std::vector<uint32_t> & indices, const std::vector<float> & tex_coords){
    #ifdef DEBUG
    GTimer timer("Normal Generator");
    #endif

    if(tex_coords.empty()){
        return;
    }

    uint32_t size_vert = vertices.size();
    uint32_t size_idx = indices.size();
    tangents_ = std::vector<float>(size_vert);
    bitangents_ = std::vector<float>(size_vert);

    for(uint32_t i = 0; i< size_idx; i+=3){
        uint32_t v1 = indices[i];
        uint32_t v2 = indices[i+1];
        uint32_t v3 = indices[i+2];
        GVec3 p1 = GVec3(vertices[v1 * 3], vertices[v1 * 3 + 1], vertices[v1 * 3 + 2]);
        GVec3 p2 = GVec3(vertices[v2 * 3], vertices[v2 * 3 + 1], vertices[v2 * 3 + 2]);
        GVec3 p3 = GVec3(vertices[v3 * 3], vertices[v3 * 3 + 1], vertices[v3 * 3 + 2]);
        GVec2 uv1 = GVec2(tex_coords[v1 * 3], tex_coords[v1 * 3 + 1]);
        GVec2 uv2 = GVec2(tex_coords[v2 * 3], tex_coords[v2 * 3 + 1]);
        GVec2 uv3 = GVec2(tex_coords[v3 * 3], tex_coords[v3 * 3 + 1]);

        GVec3 edge1 = p2 - p1;
        GVec3 edge2 = p3 - p1;
        
        float delta_u1 = tex_coords[v2 * 3] - tex_coords[v1 * 3];
        float delta_v1 = tex_coords[v2 * 3 + 1] - tex_coords[v1 * 3 + 1];
        float delta_u2 = tex_coords[v3 * 3] - tex_coords[v1 * 3];
        float delta_v2 = tex_coords[v3 * 3 + 1] - tex_coords[v1 * 3 + 1];

        float f = 1.0f / (delta_u1 * delta_v2 - delta_u2 * delta_v1);
        
        float t_x = f * (delta_v2 * edge1.x - delta_v1 * edge2.x);
        float t_y = f * (delta_v2 * edge1.y - delta_v1 * edge2.y);
        float t_z = f * (delta_v2 * edge1.z - delta_v1 * edge2.z);
        float b_x = f * (- delta_u2 * edge1.x + delta_u1 * edge2.x);
        float b_y = f * (- delta_u2 * edge1.y + delta_u1 * edge2.y);
        float b_z = f * (- delta_u2 * edge1.z + delta_u1 * edge2.z);
        
        tangents_[v1 * 3] += t_x;
        tangents_[v1 * 3 + 1] += t_y;
        tangents_[v1 * 3 + 2] += t_z;
        tangents_[v2 * 3] += t_x;
        tangents_[v2 * 3 + 1] += t_y;
        tangents_[v2 * 3 + 2] += t_z;
        tangents_[v3 * 3] += t_x;
        tangents_[v3 * 3 + 1] += t_y;
        tangents_[v3 * 3 + 2] += t_z;

        bitangents_[v1 * 3] += b_x;
        bitangents_[v1 * 3 + 1] += b_y;
        bitangents_[v1 * 3 + 2] += b_z;
        bitangents_[v2 * 3] += b_x;
        bitangents_[v2 * 3 + 1] += b_y;
        bitangents_[v2 * 3 + 2] += b_z;
        bitangents_[v3 * 3] += b_x;
        bitangents_[v3 * 3 + 1] += b_y;
        bitangents_[v3 * 3 + 2] += b_z;
    }

    for(uint32_t i = 0; i < size_vert; i+=3){
        GVec3 tangent = GNormalize(GVec3(tangents_[i], tangents_[i + 1], tangents_[i + 2]));
        GVec3 bitangent =  GNormalize(GVec3(bitangents_[i], bitangents_[i + 1], bitangents_[i + 2]));
        tangents_[i] = tangent.x;
        tangents_[i+1] = tangent.y;
        tangents_[i+2] = tangent.z;
        bitangents_[i] = bitangent.x;
        bitangents_[i+1] = bitangent.y;
        bitangents_[i+2] = bitangent.z;
    }
}

void NormalGenerator::processNormalsConcurrently(const std::vector<float> & vertices, const std::vector<uint32_t> & indices){
    #ifdef DEBUG
    GTimer timer("Normal Generator");
    #endif


    std::vector<float> normals;

    uint32_t num_of_vertices = vertices.size();
    uint32_t len_of_indices = indices.size();
    
    std::vector<std::pair<GVec3, uint32_t>> norm_of_surroundings(num_of_vertices); 

    ThreadPool & thread_pool = ThreadPool::getInstance();

    for(uint32_t i = 0 ; i < NUM_OF_THREAD_FOR_ALGO; i += 1){
        thread_pool.submitTask([this, i, &len_of_indices, &vertices, &indices, &norm_of_surroundings](){
            uint32_t offset = 3;
            uint32_t id = 0;
            uint32_t start = i * (uint32_t)(len_of_indices / NUM_OF_THREAD_FOR_ALGO);
            uint32_t end = (i + 1) * (uint32_t)(len_of_indices /  NUM_OF_THREAD_FOR_ALGO);
            std::vector<GVec3> triangle(3);
            std::vector<uint32_t> t_id(3);    
            for(uint32_t v_id = start ; v_id < end && v_id < len_of_indices; v_id++){
                triangle[id].x = vertices[indices[v_id] * offset];
                triangle[id].y = vertices[indices[v_id] * offset + 1];
                triangle[id].z = vertices[indices[v_id] * offset + 2];
                t_id[id] = indices[v_id];
                if(id == 2){
                    GVec3 norm = GNormalize(GCross(triangle[1] - triangle[0], triangle[2] - triangle[1]));

                    std::unique_lock<std::mutex> lock(cal_m_);
                    for(auto const & t_i : t_id){
                         norm_of_surroundings[t_i] = std::make_pair<GVec3, uint32_t>(norm + norm_of_surroundings[t_i].first, norm_of_surroundings[t_i].second + 1);
                    }
                    lock.unlock();
                    
                    id = 0;
                    continue;
                }
                id += 1;
            }

            std::unique_lock<std::mutex> locker(mtx_);
            num_of_completed_++;
            locker.unlock();
            is_completed_.notify_one();
        });
    }

    std::unique_lock<std::mutex> locker(mtx_);
    while(num_of_completed_ != NUM_OF_THREAD_FOR_ALGO){
        is_completed_.wait(locker);
    }


    for(auto const & [sum_norm, num]: norm_of_surroundings){
        GVec3 norm = GNormalize(sum_norm/(float)num);
        normals.push_back(norm.x);
        normals.push_back(norm.y);
        normals.push_back(norm.z);
    }
}

std::vector<float> & NormalGenerator::getNormals(){
    return normals_;
}

std::vector<float> & NormalGenerator::getTangents(){
    return tangents_;
}

std::vector<float> & NormalGenerator::getBitangents(){
    return bitangents_;
}


GENG_END