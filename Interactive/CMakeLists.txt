project(INTERACTIVE)

set(INTERACTIVE_DIR ${ROOT_DIR}/Interactive)

# imgui
set(IMGUI_DIR ${ROOT_DIR}/ThirdParties/imgui)
# glfw
set(GLFW_DIR ${ROOT_DIR}/ThirdParties/glfw3)
# gl3w
set(GL3W_DIR ${ROOT_DIR}/ThirdParties/gl3w)

# GEngine
set(GENGINE_DIR ${ROOT_DIR}/GEngine)

include_directories(
        ${INTERACTIVE_DIR}
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
        ${GLFW_DIR}/include
        ${GL3W_DIR}
        # GEngine
        ${GENGINE_DIR}/Dependencies
        ${GENGINE_DIR}/FunctionAPI
        ${GENGINE_DIR}/UserAPI
        ${GENGINE_DIR}/RenderAPI
        ${GENGINE_DIR}/GraphicsAPI
        ${GENGINE_DIR}
)

# find the cpp sources
file (GLOB SRC
        ${IMGUI_DIR}/*.h
        ${IMGUI_DIR}/*.cpp
        ${GL3W_DIR}/GL/gl3w.*
        ${IMGUI_DIR}/backends/imgui_impl_glfw.*
        ${IMGUI_DIR}/backends/imgui_impl_opengl2.*
        ${INTERACTIVE_DIR} "*.cpp"
        )

add_library(${PROJECT_NAME} ${SRC})

find_library(OPENGL_LIBRARY OpenGL REQUIRED)
find_library(COCOA_LIBRARY Cocoa REQUIRED)
find_library(IOKIT_LIBRARY IOKit REQUIRED)
find_library(COREVID_LIBRARY CoreVideo REQUIRED)

target_link_libraries(
        ${PROJECT_NAME}
        ${OPENGL_LIBRARY}
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVID_LIBRARY}
        ${GLFW_DIR}/lib/libglfw3.a
        GENGINE
)

message(STATUS "Interactive done")