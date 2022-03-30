project(USERAPI)

set(USER_DIR ${GENGINE_DIR}/UserAPI)
set(RENDER_DIR ${GENGINE_DIR}/RenderAPI)
set(GRAPHICS_DIR ${GENGINE_DIR}/GraphicsAPI)
set(FUNCTION_DIR ${GENGINE_DIR}/FunctionAPI)

include_directories(
        ${FUNCTION_DIR}
        ${USER_DIR}
        ${RENDER_DIR}
        ${GRAPHICS_DIR}
)


message(STATUS "-- UserAPI done")