#pragma once

class GLFWwindow;

namespace Mock
{
class GLFWWindow final
{
public:
    GLFWWindow();
    ~GLFWWindow();

private:
    GLFWwindow* m_window{nullptr};
};

}  // namespace Mock