#pragma once
#include <string>
#include <engine/gameplay/gameplayForward.hpp>

struct sAppWindowSettings{
    std::string appName;
    uint16_t screenWidth {800};
    uint16_t screenHeight {600};
    uint16_t frameLmit {0};
    uint16_t fixedUpdateFrequency {60}; //60 times per second update
};

class GameApp{
public:
    void RegisterScenes(std::function<void(std::string_view, LOLGameplay::SceneCreateCallbackT)>) const;
    const std::string_view GetStartSceneName() const;
    const sAppWindowSettings GetWindowSettings() const;
}; // Game

