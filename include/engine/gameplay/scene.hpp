#pragma once
#include <string_view>

#define DECLARE_SCENE(Name) \
    static constexpr std::string_view ClassName() {return #Name; }

namespace LOLGameplay{
    class IScene{
    public:
        virtual ~IScene() = default;
        virtual void Init() = 0;
        virtual void FixedUpdate(const double deltaTime) = 0;
        virtual void PostUpdate(const double deltaTime) = 0;
        virtual void Update(const double deltaTime) = 0;
        virtual void Draw() const = 0;
    }; //class IScene
} // namespace LOLGameplay
