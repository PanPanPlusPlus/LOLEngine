#pragma once
#include <Engine/CommonEngineInfo.hpp>
#include <Engine/Core/AppSettings.hpp>

extern LOLCore::sApplicationSetting GetApplicationSettings();

extern void RegisterScenes(std::function<void(std::string_view, LOLGameplay::SceneCreateCallbackT)>);