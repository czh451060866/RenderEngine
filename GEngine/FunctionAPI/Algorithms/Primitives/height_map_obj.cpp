//
// Created by 陈智辉 on 21.3.22.
//

#include "height_map_obj.h"
#include "stb_image/stb_image.h"
GENG_BEGIN

HeightMapObj::HeightMapObj(std::string path) {
    this->path = path;
}

void HeightMapObj::generateMesh(){
    // 顶点坐标
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channel, 0);
    unsigned char h;
    m_origin_data = new HeightMap[width * height];
    // Initialize the position in the image data buffer.
    int k=0;

    // Read the image data into the height map array.
    for(int j=0; j<height; j++)
    {
        for(int i=0; i<width; i++)
        {
            // Bitmaps are upside down so load bottom to top into the height map array.
            uint32_t index = (width * (height - 1 - j)) + i;

            // Get the grey scale pixel value from the bitmap image data at this location.
            h = data[k];

            // Store the pixel value as the height at this point in the height map array.
            m_origin_data[index].y = (float)h;

            // Increment the bitmap image data index.
            k+=1;
        }
        // Compensate for the extra byte at end of each line in non-divide by 2 bitmaps (eg. 257x257).
        k++;
    }

    setUpCoordinates();
    setUpModel();

    NormalGenerator normal_generator;
    normal_generator.processNormalsSingleThread(vertices_, vert_indices_);
    setNormals(normal_generator.getNormals());

    stbi_image_free(data);
    is_generated_ = true;
    mesh_t_ = HEIGHT_MAP;

}

HeightMapObj::~HeightMapObj() {
    delete[] m_height_data;
    delete[] m_origin_data;
}

void HeightMapObj::setUpCoordinates() {
    int i, j, index;
    // Loop through all the elements in the height map array and adjust their coordinates correctly.
    for(j=0; j<height; j++)
    {
        for(i=0; i<width; i++)
        {
            index = (width * j) + i;

            // Set the X and Z coordinates.
            m_origin_data[index].x = (float)i / 128.0;
            m_origin_data[index].z = -(float)j;

            // Move the terrain depth into the positive range.  For example from (0, -256) to (256, 0).
            m_origin_data[index].z += (float)(height - 1);
            m_origin_data[index].z /= 128.0;

            // Scale the height.
            m_origin_data[index].y /= 128.0;
        }
    }
}

void HeightMapObj::setUpModel() {
    int i, j, index, index1, index2, index3, index4;

    // Calculate the number of vertices in the 3D terrain model.
    int vertexCount = (height - 1) * (width - 1) * 6;

    m_height_data = new HeightMap[vertexCount];

    // Initialize the index into the height map array.
    index = 0;

    // Load the 3D terrain model with the height map terrain data.
    // We will be creating 2 triangles for each of the four points in a quad.
    for(j=0; j<(height-1); j++)
    {
        for(i=0; i<(width-1); i++)
        {
            // Get the indexes to the four points of the quad.
            index1 = (width * j) + i;          // Upper left.
            index2 = (width * j) + (i+1);      // Upper right.
            index3 = (width * (j+1)) + i;      // Bottom left.
            index4 = (width * (j+1)) + (i+1);  // Bottom right.

            // Now create two triangles for that quad.
            // Triangle 1 - Upper left.
            m_height_data[index].x = m_origin_data[index1].x;
            m_height_data[index].y = m_origin_data[index1].y;
            m_height_data[index].z = m_origin_data[index1].z;
            vertices_.push_back(m_height_data[index].x);
            vertices_.push_back(m_height_data[index].y);
            vertices_.push_back(m_height_data[index].z);
            vert_indices_.push_back(index);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            index++;

            // Triangle 1 - Upper right.
            m_height_data[index].x = m_origin_data[index2].x;
            m_height_data[index].y = m_origin_data[index2].y;
            m_height_data[index].z = m_origin_data[index2].z;
            vertices_.push_back(m_height_data[index].x);
            vertices_.push_back(m_height_data[index].y);
            vertices_.push_back(m_height_data[index].z);
            vert_indices_.push_back(index);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            index++;

            // Triangle 1 - Bottom left.
            m_height_data[index].x = m_origin_data[index3].x;
            m_height_data[index].y = m_origin_data[index3].y;
            m_height_data[index].z = m_origin_data[index3].z;
            vertices_.push_back(m_height_data[index].x);
            vertices_.push_back(m_height_data[index].y);
            vertices_.push_back(m_height_data[index].z);
            vert_indices_.push_back(index);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            index++;

            // Triangle 2 - Bottom left.
            m_height_data[index].x = m_origin_data[index3].x;
            m_height_data[index].y = m_origin_data[index3].y;
            m_height_data[index].z = m_origin_data[index3].z;
            vertices_.push_back(m_height_data[index].x);
            vertices_.push_back(m_height_data[index].y);
            vertices_.push_back(m_height_data[index].z);
            vert_indices_.push_back(index);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            index++;

            // Triangle 2 - Upper right.
            m_height_data[index].x = m_origin_data[index2].x;
            m_height_data[index].y = m_origin_data[index2].y;
            m_height_data[index].z = m_origin_data[index2].z;
            vertices_.push_back(m_height_data[index].x);
            vertices_.push_back(m_height_data[index].y);
            vertices_.push_back(m_height_data[index].z);
            vert_indices_.push_back(index);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            index++;

            // Triangle 2 - Bottom right.
            m_height_data[index].x = m_origin_data[index4].x;
            m_height_data[index].y = m_origin_data[index4].y;
            m_height_data[index].z = m_origin_data[index4].z;
            vertices_.push_back(m_height_data[index].x);
            vertices_.push_back(m_height_data[index].y);
            vertices_.push_back(m_height_data[index].z);
            vert_indices_.push_back(index);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            tex_coords_.push_back(0);
            index++;
        }
    }
    return ;
}

GENG_END