cmake_minimum_required(VERSION 3.12)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)
set(MyEngine_MAJOR_VERSION 1)
set(MyEngine_MINOR_VERSION 0)
set(MyEngine_VERSION ${MyEngine_MAJOR_VERSION}.${MyEngine_MINOR_VERSION})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(GEngine)
add_subdirectory(Interactive)
add_subdirectory(Demo)

#add_subdirectory(ThirdParties)