#pragma once
#include <chrono>

#include <Engine/Core/ITimer.hpp>

namespace LOLCore{
    class Timer : public ITimer{
    public:
        Timer();
        Timer(const int fpsLimit);
        virtual const double FrameDeltaSec() const override;

        void    SetFPSLimit(const int);
        void    RemoveFPSLimit();

        void    EndFrameUpdate();
    private: // methods
        void    RecountLimitedTimePerFrame();
        void    SyncFPSLimit();
    private: // properties
        int     _FPSLimit {0};

        double _lastFrameDelta {0.0};
        std::chrono::duration<double> _lastFrameDeltaDuration {0.0};
        std::chrono::duration<double> _limitedTimePerFrameDuration {0.0};

        std::chrono::steady_clock::time_point _previousTime;
    }; // Timer
} // namespace LOLCore
