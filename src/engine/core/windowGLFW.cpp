#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <engine/core/windowGLFW.hpp>

namespace LOLCore{
    Window::Window(const sAppWindowSettings& windowSettings)
    :_windowSettings(windowSettings){}
    Window::~Window(){}

    const bool Window::Init(){
        if(GLFW_TRUE != glfwInit()){
            spdlog::error("Failed to init GLFW");
            return false;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        _windowObject.reset(glfwCreateWindow(_windowSettings.screenWidth, _windowSettings.screenHeight, _windowSettings.appName.c_str(), nullptr, nullptr));
        if(!_windowObject){
            spdlog::error("Window is not created");
            return false;
        }

        glfwMakeContextCurrent(_windowObject.get());
        _isInited = true;
        return true;
    }

    const bool Window::ShouldClose() const{
        if(!_isInited)
            return true;
        
        return glfwWindowShouldClose(_windowObject.get());
    }

    void Window::PollEvents(){
        if(!_isInited)
            return;
        glfwPollEvents();
    }

    void Window::SwapBuffers(){
        if(!_isInited)
            return;
        
        glfwSwapBuffers(_windowObject.get());
    }
} // namespace LOLCore
