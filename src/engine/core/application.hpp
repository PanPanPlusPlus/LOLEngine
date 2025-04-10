#pragma once

#include <atomic>
#include <thread>

#include <engine/gameApp.hpp>

#include <engine/core/glfwForward.hpp>
#include <engine/gameplay/gameplayForward.hpp>


namespace LOLCore{
    class Application{
    public:
        Application();
        ~Application();

        int Execute();

    private: // structs and enums
    private: // methods
        bool Init();
        void Loop();

        void StartFixedUpdateThread();
        void StopFixedUpdateThread();

        bool InitWindow();
        void InitSceneManager();
        
        bool ValidateAppSettings();
        void CleanUp();

        void FixedUpdate(const double fixedDeltaTime);
        void Update(const double frameDeltaTime);
        void PostUpdate(const double frameDeltaTime);

        void Draw() const;
    private: // properties
        std::atomic<double> _fixedUpdateTime {0.0};
        std::atomic_bool _isRunning {false};
        std::thread _fixedUpdateThread;
        std::mutex _fixedUpdateMutex;

        GameApp _gameApp;
        GLFWwindowUPtr _window {nullptr};
        LOLGameplay::SceneManagerUPtrT _sceneManager;
    }; // Application
} // namespace LOLCore
