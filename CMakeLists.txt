cmake_minimum_required(VERSION 3.8)
project(Gestalt)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

if (MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()

set(Gestalt-SRC Sandbox/main.cpp)

add_executable(Gestalt Sandbox/main.cpp ${GLFW-CMAKE-STARTER-SRC}
        Gestalt/src/Gestalt/Scene/Scene.cpp
        Gestalt/src/Gestalt/Scene/Scene.h
        Gestalt/src/Gestalt/Scene/Entity.cpp
        Gestalt/src/Gestalt/Scene/Entity.h
        Gestalt/src/Gestalt/Scene/Components.h
        Gestalt/src/Gestalt/pch.h
        Gestalt/src/Gestalt/Renderer/Renderer.cpp
        Gestalt/src/Gestalt/Renderer/Renderer.h
        Gestalt/src/Gestalt/WindowManager/WindowManager.cpp
        Gestalt/src/Gestalt/WindowManager/WindowManager.h
        Gestalt/src/Gestalt/Events/EventBus.cpp
        Gestalt/src/Gestalt/Events/EventBus.h
        Gestalt/src/Gestalt/Events/ApplicationEvent.h
        Gestalt/src/Gestalt/Events/WindowEvent.h
)

target_link_libraries(Gestalt ${OPENGL_LIBRARIES} glfw)

