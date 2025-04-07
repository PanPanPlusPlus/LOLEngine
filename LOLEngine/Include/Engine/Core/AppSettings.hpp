#pragma once
#include <string>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLCore{
    struct sApplicationSetting{
        int screenWidth {800};
        int screenHeight {600};
        std::string appName {"LOL Engine"};
        eLogOutputType logOutputType {eLogOutputType::Console};
        uint16_t FPSLimit {0};
    }; // struct sApplicationSetting
} // namespace LOLCore
