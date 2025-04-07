#pragma once
#include <Engine/Gameplay/BaseScene.hpp>

namespace Game{
    class MenuScene : public LOLGameplay::BaseScene{
    public:
        DECLARE_SCENE(MenuScene);
        using BaseScene::BaseScene;
    };
} // namespace Game
