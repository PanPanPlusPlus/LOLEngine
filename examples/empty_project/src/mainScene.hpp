#include <engine/gameplay/scene.hpp>

namespace Game{
    class MainScene : public LOLGameplay::IScene{
    public:
        DECLARE_SCENE(MainScene)

        virtual void Init() override;
        virtual void FixedUpdate(const double deltaTime) override;
        virtual void Update(const double deltaTime) override;
        virtual void PostUpdate(const double deltaTime) override;
        virtual void Draw() const override;
    private: // structs and enums
    private: // methods
    private: // properties
    }; // MainScene
} // namespace Game
