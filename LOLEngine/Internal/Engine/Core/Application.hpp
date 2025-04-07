#pragma once
#include <GLFW/glfw3.h>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLGameplay{
    class SceneManager;
} // namespace LOLGameplay

namespace LOLCore{
    class Timer;

    class Application{
    public:
        Application();
        ~Application();

        bool Init();
        void Loop();
        void Shutdown();
    private: // properties
        ITimerPtrT _timer;
        ServiceProviderPtrT _serviceProvider;
        std::unique_ptr<LOLGameplay::SceneManager> _sceneManager;

        bool _isInited {false};
        GLFWwindow* _mainWindow {nullptr};
    }; // Application
} // namespace LOLCore
