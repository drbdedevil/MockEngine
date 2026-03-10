#pragma once

#include <string>
#include <functional>

#include "Core/Utility.h"
#include "Window/IWindow.h"

class GLFWwindow;

namespace Mock
{
class GLFWWindow final : public IWindow, public NonCopyable
{
public:
    GLFWWindow(const WindowSettings& settings);
    ~GLFWWindow() override;

    void setTitle(const std::string& title) override;
    bool isValid() const override;
    bool shouldClose() const override;

private:
    GLFWwindow* m_window{nullptr};
};

}  // namespace Mock