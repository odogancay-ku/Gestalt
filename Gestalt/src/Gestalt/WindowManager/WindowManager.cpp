#include <cstdlib>
#include <iostream>
#include "WindowManager.h"

GLFWwindow* WindowManager::primaryWindow = nullptr;

void WindowManager::Init(const char *title) {
    // Initialize GLFW
    if (!glfwInit()) {
        // Initialization failed
        std::cerr << "GLFW initialization failed" << std::endl;
        exit(1);
    }

    // Create a fullscreen window
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int windowWidth = mode->width;
    int windowHeight = mode->height;

    // Create a window
    primaryWindow = glfwCreateWindow(windowWidth, windowHeight, title, nullptr, nullptr);
    if (!primaryWindow) {
        // Window or OpenGL context creation failed
        glfwTerminate();
        std::cerr << "Window or OpenGL context creation failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Make the window's context current
    glfwMakeContextCurrent(primaryWindow);

    glfwSetKeyCallback(primaryWindow, KeyCallback);
    glfwSetCursorPosCallback(primaryWindow, MouseCallback);
    glfwSetMouseButtonCallback(primaryWindow, MouseButtonCallback);
    glfwSetScrollCallback(primaryWindow, ScrollCallback);
    glfwSetWindowSizeCallback(primaryWindow, WindowResizeCallback);

}

void WindowManager::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {

}

void WindowManager::MouseCallback(GLFWwindow *window, double xpos, double ypos) {

}

void WindowManager::MouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {

}

void WindowManager::ScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {

}

void WindowManager::WindowResizeCallback(GLFWwindow *window, int width, int height) {

}
