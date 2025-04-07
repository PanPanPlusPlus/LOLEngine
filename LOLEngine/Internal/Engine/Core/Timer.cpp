#include <thread>

#include <Engine/Core/Timer.hpp>

namespace LOLCore{
    Timer::Timer(){
        _previousTime = std::chrono::high_resolution_clock::now();
        _lastFrameDelta = 1.0/ 120.0;
    }

    Timer::Timer(const int fpsLimit)
    : _FPSLimit(fpsLimit){
        _previousTime = std::chrono::high_resolution_clock::now();
        RecountLimitedTimePerFrame();
        _lastFrameDelta = _limitedTimePerFrameDuration.count();
    }

    const double Timer::FrameDeltaSec() const{
        return _lastFrameDelta;
    }

    void Timer::SetFPSLimit(const int fpsLimit){
        _FPSLimit = fpsLimit;
        RecountLimitedTimePerFrame();
    }

    void Timer::RemoveFPSLimit(){
        _FPSLimit = 0;
        RecountLimitedTimePerFrame();
    }
    
    void Timer::EndFrameUpdate(){
        auto currentTime = std::chrono::high_resolution_clock::now();
        _lastFrameDeltaDuration = currentTime - _previousTime;
        _lastFrameDelta = _lastFrameDeltaDuration.count();
        _previousTime = currentTime;
        SyncFPSLimit();
    }

// private: // methods
    void Timer::RecountLimitedTimePerFrame(){
        if(_FPSLimit > 0)
            _limitedTimePerFrameDuration = std::chrono::duration<double>(1.0 / static_cast<double>(_FPSLimit));
        else
            _limitedTimePerFrameDuration = std::chrono::duration<double>(0.0);
    }

    void Timer::SyncFPSLimit(){
        if(_FPSLimit == 0)
            return;
        if(_lastFrameDeltaDuration > _limitedTimePerFrameDuration)
            return;
        std::this_thread::sleep_for(_limitedTimePerFrameDuration - _lastFrameDeltaDuration);
    }

} // namespace LOLCore
