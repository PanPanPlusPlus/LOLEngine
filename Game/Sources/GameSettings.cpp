#include <Engine/ExternalSettings.hpp>

LOLCore::sApplicationSetting GetApplicationSettings(){
    return {
        .screenWidth = 1024,
        .screenHeight = 768,
        .appName = "Game 1",
        .logOutputType = LOLCore::eLogOutputType::Console,
        .FPSLimit = 120,
    };
}

