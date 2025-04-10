#include <spdlog/spdlog.h>

#include <engine/gameApp.hpp>

#include <engine/gameplay/sceneManager.hpp>
#include <engine/gameplay/scene.hpp>


namespace LOLGameplay{
    SceneManager::SceneManager(){}

    SceneManager::~SceneManager(){}
    
    void SceneManager::FixedUpdate(const double frameDelta){
        if(!_currentScene)
            return;
        _currentScene->FixedUpdate(frameDelta);
    }

    void SceneManager::Update(const double frameDelta){
        if(!_currentScene)
            return;
        _currentScene->Update(frameDelta);
    }

    void SceneManager::PostUpdate(const double frameDelta){
        if(!_currentScene)
            return;
        _currentScene->PostUpdate(frameDelta);
    }

    void SceneManager::Draw() const{
        if(!_currentScene)
            return;
        _currentScene->Draw();
    }

    void SceneManager::SetCurrentScene(std::string_view sceneName){
        _currentScene = CreateScene(sceneName);
        if(_currentScene)
            _currentScene->Init();
    }

    void SceneManager::RegisterScene(std::string_view sceneName, SceneCreateCallbackT factoryCallback){
        if(sceneName.empty()){
            spdlog::error("Failed to register scene. Class name is empty");
            return;
        }

        if(!factoryCallback){
            spdlog::error("Failed to register scene {}. Factory callback is null", sceneName);
            return;
        }

        if(_sceneFactoryRegistry.end() != _sceneFactoryRegistry.find(sceneName)){
            spdlog::warn("Scene {} is already registered", sceneName);
            return;
        }

        _sceneFactoryRegistry[sceneName] = factoryCallback;
    }
    
// private: // methods
    ISceneSPtrT SceneManager::CreateScene(std::string_view sceneName) const{
        auto registryIt = _sceneFactoryRegistry.find(sceneName);
        if(_sceneFactoryRegistry.end() == registryIt){
            spdlog::error("Scene {} not registred", sceneName);
            return nullptr;
        }
        return registryIt->second();
    }
} // namespace LOLGameplay
