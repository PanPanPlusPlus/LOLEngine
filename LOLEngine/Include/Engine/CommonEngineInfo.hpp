#pragma once
#include <memory>
#include <functional>

namespace LOLCore{
    class ServiceProvider;
    using ServiceProviderPtrT = std::shared_ptr<ServiceProvider>;

    class ITimer;
    using ITimerPtrT = std::shared_ptr<ITimer>;
    using ITimerConstPtrT = std::shared_ptr<const ITimer>;

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

    class Logger;
    using LoggerPtrT = std::shared_ptr<Logger>;
    using LoggerConstPtrT = std::shared_ptr<const Logger>;
} // namespace LOLCore

namespace LOLGameplay{
    class BaseScene;

    using ScenePtrT = std::unique_ptr<BaseScene>;
    using SceneCreateCallbackT = std::function<ScenePtrT(LOLCore::ServiceProviderPtrT)>;

    class ISceneNode;
} // namespace LOLGameplay
