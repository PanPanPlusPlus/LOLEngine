#pragma once
#include <Engine/CommonEngineInfo.hpp>

#define DECLARE_SCENE(Name) \
    static constexpr std::string_view ClassName() {return #Name; }

namespace LOLGameplay{
    class BaseScene{
    public:
        DECLARE_SCENE(BaseScene)

        virtual ~BaseScene();
        virtual void Init();
        virtual void Update(const double deltaTime);
        virtual void Draw() const;

        BaseScene(LOLCore::ServiceProviderPtrT);
    protected:
        LOLCore::ServiceProviderPtrT _serviceProvider;
    }; //class BaseScene
} // namespace LOLGameplay
