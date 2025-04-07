#pragma once
#include <string_view>
#include <fstream>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLCore{
    
    class Logger{
    public:
        Logger() = delete;
        Logger(eLogOutputType);
        ~Logger();

        void Log(std::string_view) const;
        void Log(eLogLevel, std::string_view) const;
    private: // properties
        eLogOutputType _LogOutputType {eLogOutputType::Console};
        mutable std::ofstream _outLogFile;
    }; // Logger
} // namespace LOLCore
