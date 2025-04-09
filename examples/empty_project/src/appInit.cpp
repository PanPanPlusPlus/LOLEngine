#include <engine/engineInit.hpp>
#include <mainScene.hpp>

LOLCore::sApplicationSettings GetApplicationSettings(){
    return {
        .appName {"Empty example"},
        .startScene {Game::MainScene::ClassName()},
    };
}

void RegisterScenes(std::function<void(std::string_view, LOLGameplay::SceneCreateCallbackT)> callback){
    LOLGameplay::RegisterSceneType<Game::MainScene>(callback);
}