#pragma once

#include <memory>

namespace Mock
{

    class GLFWWindow;

class GLFWWindowManager  final
{
public:
    GLFWWindowManager();
    ~GLFWWindowManager();

private:
    std::shared_ptr<GLFWWindow> m_window;
    bool m_initialized{false};
};

} // namespace Mock