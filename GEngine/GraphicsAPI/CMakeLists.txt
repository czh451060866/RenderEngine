project(GRAPHICSAPI)

set(GRAPHICS_DIR ${GENGINE_DIR}/GraphicsAPI)
#
#aux_source_directory(${GRAPHICS_DIR} GRAPHICS_SRC)
#aux_source_directory(${GRAPHICS_DIR}/opengl GRAPHICS_SRC)

include_directories(
        ${GRAPHICS_DIR}
)
#
#add_library(${PROJECT_NAME} ${GRAPHICS_SRC})

message(STATUS "-- GraphicsAPI done")