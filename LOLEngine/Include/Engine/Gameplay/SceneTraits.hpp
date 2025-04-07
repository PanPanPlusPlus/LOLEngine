#pragma once

#include <concepts>
#include <string_view>

#include <Engine/CommonEngineInfo.hpp>

namespace LOLGameplay{
    template<typename T>
    concept Scene = requires{
        {T::ClassName()} -> std::convertible_to<std::string_view>;
        requires std::derived_from<T, BaseScene>;
        requires std::constructible_from<T, LOLCore::ServiceProviderPtrT>;
    };

    template<Scene T>
    struct sSceneTraits{
        static constexpr std::string_view Name = T::ClassName();
        static ScenePtrT Create(LOLCore::ServiceProviderPtrT serviceProvider){
            return std::make_unique<T>(serviceProvider);
        }
    };

    template<Scene T>
    void RegisterSceneType(auto registerCallback) {
        sSceneTraits<T> traits;
        registerCallback(traits.Name, &traits.Create);
    }
} // namespace LOLGameplay
