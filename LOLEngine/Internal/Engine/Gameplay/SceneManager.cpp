
#include <Engine/ExternalSettings.hpp>

#include <Engine/Core/ServiceProvider.hpp>
#include <Engine/Core/Logger.hpp>

#include <Engine/Gameplay/SceneTraits.hpp>
#include <Engine/Gameplay/SceneManager.hpp>
#include <Engine/Gameplay/BaseScene.hpp>

namespace LOLGameplay{
    SceneManager::SceneManager(LOLCore::ServiceProviderPtrT serviceProvider)
    : _serviceProvider(serviceProvider){

        auto registryCallback =  [this](std::string_view name, SceneCreateCallbackT factory){
            RegisterScene(name, factory);
        };
        // register engine scenes
        RegisterSceneType<BaseScene>(registryCallback);
        // register game scenes
        RegisterScenes(registryCallback);
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
    }
    
// private: // methods
    ScenePtrT SceneManager::CreateScene(std::string_view sceneName) const{
        auto registryIt = _sceneFactoryRegistry.find(sceneName);
        if(_sceneFactoryRegistry.end() == registryIt){
            _serviceProvider->GetService<LOLCore::Logger>()->LogError(std::format("Scene {} not registred", sceneName));
            return nullptr;
        }
        return registryIt->second(_serviceProvider);
    }

    void SceneManager::RegisterScene(std::string_view sceneName, SceneCreateCallbackT factoryCallback){
        auto logger = _serviceProvider->GetService<LOLCore::Logger>();
        if(sceneName.empty()){
            logger->LogError("Failed to register scene. Class name is empty");
            return;
        }

        if(!factoryCallback){
            logger->LogError(std::format("Failed to register scene {}. Factory callback is null", sceneName));
            return;
        }

        if(_sceneFactoryRegistry.end() != _sceneFactoryRegistry.find(sceneName)){
            logger->Log(LOLCore::eLogLevel::Warning, std::format("Scene {} is already registered", sceneName));
            return;
        }

        _sceneFactoryRegistry[sceneName] = factoryCallback;
    }
} // namespace LOLGameplay
