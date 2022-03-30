cmake_minimum_required(VERSION 3.12)
project(GENGINE)
set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(GENGINE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "GEngine Configuring")

set(USER_DIR ${GENGINE_DIR}/UserAPI)
set(RENDER_DIR ${GENGINE_DIR}/RenderAPI)
set(GRAPHICS_DIR ${GENGINE_DIR}/GraphicsAPI)
set(FUNCTION_DIR ${GENGINE_DIR}/FunctionAPI)
set(DEPEND_DIR ${GENGINE_DIR}/Dependencies)

include_directories(
        ${GENGINE_DIR}
        ${FUNCTION_DIR}
        ${GRAPHICS_DIR}
        ${RENDER_DIR}
        ${USER_DIR}
        ${DEPEND_DIR}
)

add_subdirectory(GraphicsAPI)
add_subdirectory(RenderAPI)
add_subdirectory(FunctionAPI)
add_subdirectory(UserAPI)


file(GLOB_RECURSE GENG_SRC
        "${USER_DIR}/*.cpp"
        "${FUNCTION_DIR}/*.cpp"
)

add_library(${PROJECT_NAME} ${GENG_SRC})

target_link_libraries(
        ${PROJECT_NAME}
        RENDERAPI
)


message(STATUS "GEngine done")
