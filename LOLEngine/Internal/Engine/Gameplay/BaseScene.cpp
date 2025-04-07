#include <Engine/Core/ServiceProvider.hpp>

#include <Engine/Gameplay/BaseScene.hpp>

namespace LOLGameplay{
    BaseScene::BaseScene(LOLCore::ServiceProviderPtrT serviceProvider)
    : _serviceProvider(serviceProvider){}

    BaseScene::~BaseScene(){}

    void BaseScene::Init(){}

    void BaseScene::Update(const double deltaTime){}

    void BaseScene::Draw() const{}

} // namespace LOLGameplay
