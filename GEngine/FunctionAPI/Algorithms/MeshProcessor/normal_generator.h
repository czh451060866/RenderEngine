//
// Created by HongZh on 2022/03/11, 00:19:50
//

#ifndef MYENGINE_NORMAL_GENERATOR_H
#define MYENGINE_NORMAL_GENERATOR_H

#include "Algorithms/algo_predeclared.h"

GENG_BEGIN

#define NUM_OF_THREAD_FOR_ALGO 3

class NormalGenerator{
private:
    uint32_t num_of_completed_;
    std::mutex mtx_;
    std::mutex cal_m_;
    std::condition_variable is_completed_;

    std::vector<float> normals_;
    std::vector<float> tangents_;
    std::vector<float> bitangents_;
public:
    NormalGenerator();
    ~NormalGenerator();

    std::vector<float> & getNormals();
    std::vector<float> & getTangents();
    std::vector<float> & getBitangents();
    void processNormalsSingleThread(const std::vector<float> & vertices, const std::vector<uint32_t> & indices);
    void processTangentsSingleThread(const std::vector<float> & vertices, const std::vector<uint32_t> & indices, const std::vector<float> & tex_coords);
    void processNormalsConcurrently(const std::vector<float> & vertices, const std::vector<uint32_t> & indices);
};

GENG_END

#endif //MYENGINE_NORMAL_GENERATOR_H