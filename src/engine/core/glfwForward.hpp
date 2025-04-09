#pragma once
#include <memory>

struct GLFWwindow;
struct GLFWwindowDeleter{
    void operator()(GLFWwindow*) const;
};
using GLFWwindowUPtr = std::unique_ptr<GLFWwindow, GLFWwindowDeleter>;