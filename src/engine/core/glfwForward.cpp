#include <GLFW/glfw3.h>
#include <engine/core/glfwForward.hpp>

void GLFWwindowDeleter::operator()(GLFWwindow* window) const{
    glfwDestroyWindow(window);
}