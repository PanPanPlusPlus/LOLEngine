#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>

#include <Engine/ExternalSettings.hpp>

int main(){
    if(!glfwInit())
        return EXIT_FAILURE;

    auto appSettings = GetApplicationSettings();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    auto window = glfwCreateWindow(appSettings.screenWidth, appSettings.screenHeight, appSettings.appName.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}