#pragma once
#include <string>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLCore{
    struct sApplicationSetting{
        uint16_t screenWidth {800};
        uint16_t screenHeight {600};
        uint16_t FPSLimit {0};

        std::string appName {"LOL Engine"};
        std::string_view startSceneName {};

        eLogOutputType logOutputType {eLogOutputType::Console};
    }; // struct sApplicationSetting
} // namespace LOLCore
