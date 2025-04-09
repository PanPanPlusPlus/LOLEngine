#include <spdlog/spdlog.h>

#include <engine/engineInit.hpp>

#include <engine/gameplay/sceneManager.hpp>
#include <engine/gameplay/scene.hpp>


namespace LOLGameplay{
    SceneManager::SceneManager(){
        
        RegisterScenes([this](std::string_view name, SceneCreateCallbackT factory){
            RegisterScene(name, factory);
        });
    }

    SceneManager::~SceneManager(){}
    
    void SceneManager::Update(const double frameDelta){
        if(!_currentScene)
            return;
        _currentScene->Update(frameDelta);
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
    
// private: // methods
    ISceneSPtrT SceneManager::CreateScene(std::string_view sceneName) const{
        auto registryIt = _sceneFactoryRegistry.find(sceneName);
        if(_sceneFactoryRegistry.end() == registryIt){
            spdlog::error("Scene {} not registred", sceneName);
            return nullptr;
        }
        return registryIt->second();
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
} // namespace LOLGameplay
