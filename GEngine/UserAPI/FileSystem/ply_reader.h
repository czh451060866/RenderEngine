//
// Created by HongZh on 2022/03/10, 18:10:15
//

#ifndef MYENGINE_PLY_READER_H
#define MYENGINE_PLY_READER_H

#include "file_handler_predeclared.h"

GENG_BEGIN

class PlyReader{
public:
    PlyReader();
    ~PlyReader();
    static void readPLYFile(const std::string & path, PLYInfo * ply_file);
};

GENG_END

#endif //MYENGINE_PLY_READER_H