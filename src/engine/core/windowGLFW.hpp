#pragma once

#include <engine/gameApp.hpp>
#include <engine/core/glfwForward.hpp>

namespace LOLCore{
    class Window{
    public:
        Window(const sAppWindowSettings&);
        ~Window();

        const bool Init();
        const bool ShouldClose() const;
        void PollEvents();
        void SwapBuffers();

        Window() = delete;
        Window(const Window&) = delete;
        Window(const Window&&) = delete;
    private: // structs and enums
    private: // methods
    private: // properties
        bool _isInited {false};
        GLFWwindowUPtr _windowObject {nullptr};
        sAppWindowSettings _windowSettings;
    }; // Window
} // namespace LOLCore
