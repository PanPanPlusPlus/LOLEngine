#pragma once

#include <engine/engineInit.hpp>
#include <engine/core/glfwForward.hpp>
#include <engine/gameplay/gameplayForward.hpp>


namespace LOLCore{
    class Application{
    public:
        Application();
        ~Application();

        int Start();

    private: // structs and enums
    private: // methods
        bool Init();
        void Loop();

        bool InitWindow();
        void InitSceneManager();
        
        bool ValidateAppSettings();
        void CleanUp();

        void Update(const float deltaFrame);
        void Draw() const;
    private: // properties
        const sApplicationSettings _appSettings;

        GLFWwindowUPtr _window {nullptr};
        LOLGameplay::SceneManagerUPtrT _sceneManager;
    }; // Application
} // namespace LOLCore
