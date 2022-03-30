cmake_minimum_required(VERSION 3.12)

project(DEMO)

# Interactive
set(INTERACTIVE_DIR ${ROOT_DIR}/Interactive)

# GEngine
set(GENGINE_DIR ${ROOT_DIR}/GEngine)

# imgui
set(IMGUI_DIR ${ROOT_DIR}/ThirdParties/imgui)

# glfw
set(GLFW_DIR ${ROOT_DIR}/ThirdParties/glfw3)

# gl3w
set(GL3W_DIR ${ROOT_DIR}/ThirdParties/gl3w)

include_directories(
        # gui
        ${INTERACTIVE_DIR}
        #
        ${GENGINE_DIR}
        ${GENGINE_DIR}/FunctionAPI
        ${GENGINE_DIR}/RenderAPI
        ${GENGINE_DIR}/GraphicsAPI
        ${GENGINE_DIR}/UserAPI
        ${GENGINE_DIR}/Dependencies

        # imgui
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
        ${GLFW_DIR}/include
        ${GL3W_DIR}
)

# find the cpp sources
file (GLOB SRC
        ./openWindow/main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})


target_link_libraries(${PROJECT_NAME}
        INTERACTIVE
)


message(STATUS "Demo done")