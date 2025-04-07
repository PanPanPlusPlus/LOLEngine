#pragma once
#include <memory>

namespace LOLCore{
    class ServiceProvider;
    using ServiceProviderPtr = std::shared_ptr<ServiceProvider>;

    class ITimer;
    using ITimerPtr = std::shared_ptr<ITimer>;

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
