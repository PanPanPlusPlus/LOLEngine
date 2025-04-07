#include <iostream>
#include <unordered_map>
#include <format>

#include <Engine/Core/Logger.hpp>

namespace LOLCore{
    static const std::unordered_map<eLogLevel, std::string_view> gLogPrefixMap {
        {eLogLevel::Info,       "INFO"},
        {eLogLevel::Warning,    "WARNING"},
        {eLogLevel::Error,      "ERROR"},
        {eLogLevel::Critical,   "CRITICAL"}
    };

    Logger::Logger(eLogOutputType logOutputType)
    : _LogOutputType (logOutputType) {} 

    Logger::~Logger(){
        if(_outLogFile.is_open())
            _outLogFile.close();
    }

    void Logger::Log(std::string_view message) const{
        Log(eLogLevel::Info, message);
    }

    void Logger::Log(eLogLevel logLevel, std::string_view message) const{
        auto logPrefixIt = gLogPrefixMap.find(logLevel);
        auto logPrefix = gLogPrefixMap.end() != logPrefixIt ? logPrefixIt->second : "UNKNOWN";
        auto formattedMessage = std::format("{} : {}\n", logPrefix, message);
        
        if(eLogOutputType::Console == _LogOutputType || eLogOutputType::ConsoleAndFile == _LogOutputType)
            std::cout << formattedMessage;

        if(eLogOutputType::File == _LogOutputType || eLogOutputType::ConsoleAndFile == _LogOutputType){
            if(!_outLogFile.is_open())
                _outLogFile.open("Log.txt", std::ios::out);

            if(_outLogFile.is_open())
                _outLogFile << formattedMessage;
        }
    }

} // namespace LOLCore
