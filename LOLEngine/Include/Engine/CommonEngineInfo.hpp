#pragma once
#include <memory>

namespace LOLCore{
    class ServiceProvider;
    using ServiceProviderPtr = std::shared_ptr<ServiceProvider>;

    enum class eLogLevel{
        Info,
        Warning,
        Error,
        Critical,
    }; // eLogLevel

    enum class eLogOutputType{
        Console,
        File,
        ConsoleAndFile,
    }; //eLogOutput
} // namespace LOLCore
