#include <engine/gameApp.hpp>
#include <mainScene.hpp>

void GameApp::RegisterScenes(std::function<void(std::string_view, LOLGameplay::SceneCreateCallbackT)> callback) const{
    LOLGameplay::RegisterSceneType<Game::MainScene>(callback);
}

const std::string_view GameApp::GetStartSceneName() const{
    return Game::MainScene::ClassName();
}

const sAppWindowSettings GameApp::GetWindowSettings() const{
    return {
        .appName {"Empty example"},
    };
}