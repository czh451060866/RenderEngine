//
// Created by zhanghong50 on 2022/2/1.
//

#ifndef MYENGINE_DATA_POOL_H
#define MYENGINE_DATA_POOL_H

#include "general_include.h"
#include "RenderModules/data_mod.h"
#include "RenderData/render_mesh.h"
#include "RenderModules/shader_mod.h"

GENG_BEGIN

class DataPool {
public:
    static DataPool & getInstance();
    ~DataPool();
    DataPool(const DataPool &) = delete;
    DataPool& operator=(const DataPool &) = delete;

    std::vector<std::shared_ptr<DataModule>>  loadData(std::shared_ptr<RenderMesh> mesh); // load data from mesh and shader
private:
    std::vector<std::vector<std::shared_ptr<DataModule>>> data_pool_;
    uint32_t activated_id_;
    DataPool();
};

GENG_END


#endif //MYENGINE_DATA_POOL_H
