#pragma once
#include <GLFW/glfw3.h>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLCore{
    class Application{
    public:
        Application() = default;
        ~Application();

        bool Init();
        void Loop();
        void Shutdown();
    private: // properties
        ServiceProviderPtr _serviceProvider;
        bool _isInited {false};
        GLFWwindow* _mainWindow {nullptr};
    }; // Application
} // namespace LOLCore
