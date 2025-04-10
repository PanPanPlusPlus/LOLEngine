#pragma once
#include <map>

#include <engine/gameplay/gameplayForward.hpp>

namespace LOLGameplay{
    class SceneManager{
    public:
        SceneManager();
        ~SceneManager();
        
        void FixedUpdate(const double frameDelta);
        void Update(const double frameDelta);
        void PostUpdate(const double frameDelta);
        void Draw() const;

        void SetCurrentScene(std::string_view sceneName);
        void RegisterScene(std::string_view, SceneCreateCallbackT);
    private: // methods
        ISceneSPtrT CreateScene(std::string_view) const;
    private: // properties
        std::map<std::string_view, SceneCreateCallbackT> _sceneFactoryRegistry;

        ISceneSPtrT _currentScene {nullptr};
    }; // SceneManager
} // namespace LOLGameplay
