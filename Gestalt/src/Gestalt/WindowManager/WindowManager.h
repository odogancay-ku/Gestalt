#ifndef GESTALT_WINDOWMANAGER_H
#define GESTALT_WINDOWMANAGER_H

#include <GLFW/glfw3.h>

class WindowManager {
public:
    static GLFWwindow* primaryWindow;

    static void Init(const char* title);

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    static void WindowResizeCallback(GLFWwindow* window, int width, int height);
};


#endif //GESTALT_WINDOWMANAGER_H
