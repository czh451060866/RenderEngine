project(RENDERAPI)

set(RENDER_DIR ${GENGINE_DIR}/RenderAPI)
set(GRAPHICS_DIR ${GENGINE_DIR}/GraphicsAPI)
set(DEPEND_DIR ${GENGINE_DIR}/Dependencies)

include_directories(
        ${RENDER_DIR}

        ${GRAPHICS_DIR}
        ${GRAPHICS_DIR}/opengl

        ${DEPEND_DIR}
        ${DEPEND_DIR}/glew/include
)

#aux_source_directory(${RENDER_DIR} RENDER_SRC)
#aux_source_directory(${GRAPHICS_DIR} RENDER_SRC)
file(GLOB_RECURSE RENDER_SRC "${RENDER_DIR}/*.cpp" "${GRAPHICS_DIR}/*.cpp")

add_library(${PROJECT_NAME} ${RENDER_SRC})

target_link_libraries(
        ${PROJECT_NAME}
        ${DEPEND_DIR}/glew/lib/libGLEW.a
)
message(STATUS "-- RenderAPI done")