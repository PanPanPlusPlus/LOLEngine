#include <Engine/ExternalSettings.hpp>

#include <Scenes/MenuScene.hpp>

LOLCore::sApplicationSetting GetApplicationSettings(){
    return {
        .screenWidth = 1024,
        .screenHeight = 768,
        .appName = "Game 1",
        .logOutputType = LOLCore::eLogOutputType::Console,
        .FPSLimit = 120,
        .startSceneName = Game::MenuScene::ClassName()
    };
}

