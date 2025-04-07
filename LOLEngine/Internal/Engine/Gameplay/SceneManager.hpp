#pragma once
#include <map>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLGameplay{
    class SceneManager{
    public:
        SceneManager() = delete;
        SceneManager(LOLCore::ServiceProviderPtrT);
        ~SceneManager();
        
        void Update(const double frameDelta);
        void Draw() const;

        void SetCurrentScene(std::string_view sceneName);
        
    private: // methods
        ScenePtrT CreateScene(std::string_view) const;
        void RegisterScene(std::string_view, SceneCreateCallbackT);
    private: // properties
        LOLCore::ServiceProviderPtrT _serviceProvider;
        std::map<std::string_view, SceneCreateCallbackT> _sceneFactoryRegistry;

        ScenePtrT _currentScene {nullptr};
    }; // SceneManager
} // namespace LOLGameplay
