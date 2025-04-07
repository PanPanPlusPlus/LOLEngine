#pragma once

namespace LOLCore{
    class ITimer{
    public:
        virtual ~ITimer() = default;
        virtual const double FrameDeltaSec() const = 0;
    };
} // namespace LOLCode
