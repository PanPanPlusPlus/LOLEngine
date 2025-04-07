#include <Engine/ExternalSettings.hpp>
#include <Engine/Gameplay/SceneTraits.hpp>

#include <Scenes/MenuScene.hpp>

void RegisterScenes(std::function<void(std::string_view, LOLGameplay::SceneCreateCallbackT)> callback){
    // for example
    LOLGameplay::RegisterSceneType<Game::MenuScene>(callback);
}