#pragma once
#include <map>

#include <engine/gameplay/gameplayForward.hpp>

namespace LOLGameplay{
    class SceneManager{
    public:
        SceneManager();
        ~SceneManager();
        
        void Update(const double frameDelta);
        void Draw() const;

        void SetCurrentScene(std::string_view sceneName);
        
    private: // methods
        ISceneSPtrT CreateScene(std::string_view) const;
        void RegisterScene(std::string_view, SceneCreateCallbackT);
    private: // properties
        std::map<std::string_view, SceneCreateCallbackT> _sceneFactoryRegistry;

        ISceneSPtrT _currentScene {nullptr};
    }; // SceneManager
} // namespace LOLGameplay
