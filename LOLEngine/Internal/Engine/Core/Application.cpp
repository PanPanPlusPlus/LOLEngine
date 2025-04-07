#include <Engine/ExternalSettings.hpp>

#include <Engine/Core/Application.hpp>
#include <Engine/Core/Logger.hpp>
#include <Engine/Core/Timer.hpp>
#include <Engine/Core/ServiceProvider.hpp>

namespace LOLCore{

    Application::~Application(){}

    bool Application::Init(){
    
        if(_isInited){
            if(_serviceProvider)
                _serviceProvider->GetService<Logger>()->Log(eLogLevel::Warning, "Application is already inited");
            return false;
        }

        auto applicationSettings = GetApplicationSettings();

        _timer = std::make_shared<Timer>(applicationSettings.FPSLimit);

        _serviceProvider = std::make_shared<ServiceProvider>();
        _serviceProvider->RegisterService<Logger>(std::make_shared<Logger>(applicationSettings.logOutputType));
        _serviceProvider->RegisterService<ITimer>(_timer);

        auto logger = _serviceProvider->GetService<Logger>();

        if(!glfwInit()){
            logger->Log(eLogLevel::Critical, "Failed to init GLFW");
            return false;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        _mainWindow = glfwCreateWindow(applicationSettings.screenWidth, applicationSettings.screenHeight, 
                                        applicationSettings.appName.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(_mainWindow);
        
        _isInited = true;
        
        return true;
    }

    void Application::Loop(){
        if(!_isInited)
            return;

        while(!glfwWindowShouldClose(_mainWindow)){
            glfwPollEvents();
            glClearColor(0.f ,0.f,0.f,1.f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(_mainWindow);

            std::static_pointer_cast<Timer>(_timer)->EndFrameUpdate();
        }
    
    }

    void Application::Shutdown(){
        glfwDestroyWindow(_mainWindow);
        glfwTerminate();
    }

} // namespace LOLCore
