#pragma once

#include <concepts>
#include <string_view>
#include <memory>
#include <functional>

namespace LOLGameplay{
    class IScene;
    using ISceneSPtrT = std::shared_ptr<IScene>;
    using SceneCreateCallbackT = std::function<ISceneSPtrT()>;

    class SceneManager;
    using SceneManagerUPtrT = std::unique_ptr<SceneManager>;

    template<typename T>
    concept Scene = requires{
        {T::ClassName()} -> std::convertible_to<std::string_view>;
        requires std::derived_from<T, IScene>;
    };

    template<Scene T>
    struct sSceneTraits{
        static constexpr std::string_view Name = T::ClassName();
        static ISceneSPtrT Create(){
            return std::make_unique<T>();
        }
    };

    template<Scene T>
    void RegisterSceneType(auto registerCallback) {
        sSceneTraits<T> traits;
        registerCallback(traits.Name, &traits.Create);
    }
} // namespace LOLGameplay
