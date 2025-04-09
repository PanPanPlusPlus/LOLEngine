#pragma once
#include <string>
#include <engine/gameplay/gameplayForward.hpp>

namespace LOLCore{
    struct sApplicationSettings{
        std::string appName {"LoL engine"};
        uint16_t screenWidth {800};
        uint16_t screenHeight {600};
        uint16_t frameLimit {0};
        std::string_view startScene {};
    }; //struct sApplicationSettings
} // namespace 

extern LOLCore::sApplicationSettings GetApplicationSettings();
extern void RegisterScenes(std::function<void(std::string_view, LOLGameplay::SceneCreateCallbackT)>);