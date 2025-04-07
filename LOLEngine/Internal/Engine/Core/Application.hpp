#pragma once
#include <GLFW/glfw3.h>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLCore{
    class Timer;

    class Application{
    public:
        Application() = default;
        ~Application();

        bool Init();
        void Loop();
        void Shutdown();
    private: // properties
        ITimerPtr _timer;
        ServiceProviderPtr _serviceProvider;
        bool _isInited {false};
        GLFWwindow* _mainWindow {nullptr};
    }; // Application
} // namespace LOLCore
