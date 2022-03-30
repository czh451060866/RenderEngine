//
// Created by 陈智辉 on 21.3.22.
//

#ifndef MYENGINE_HEIGHT_MAP_OBJ_H
#define MYENGINE_HEIGHT_MAP_OBJ_H

#include "base_obj.h"

GENG_BEGIN

class HeightMapObj : public BaseObject{
private:
    struct HeightMap{
        float x, y, z;
    };
    std::string path;
    int width;
    int height;
    int channel;
    HeightMap* m_height_data;
    HeightMap* m_origin_data;
    virtual void generateMesh() override;
    void setUpCoordinates();
    void setUpModel();
public:
    HeightMapObj(std::string path);
    ~HeightMapObj();
};

GENG_END
#endif //MYENGINE_HEIGHT_MAP_OBJ_H
