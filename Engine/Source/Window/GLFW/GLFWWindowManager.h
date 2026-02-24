#pragma once

#include "GLFWWindow.h"

#include <memory>
#include <unordered_map>
#include <expected>

namespace Mock
{

enum class WindowCreationError
{
    ManagerIsNotInitialized = 0,
    CreationFailed = 1
};

class GLFWWindowManager  final
{
public:
    GLFWWindowManager();
    ~GLFWWindowManager();

    void update();
    bool areAllWindowsClosed() const;

    std::expected<WindowId, WindowCreationError> createWindow(const WindowSettings& settings);
    std::shared_ptr<GLFWWindow> getWindowById(WindowId id) const;

private:
    std::unordered_map<WindowId, std::shared_ptr<GLFWWindow>> m_windows;
    WindowId m_windowIdCounter{1};
    bool m_initialized{false};

    void cleanupClosedWindows();
};

} // namespace Mock