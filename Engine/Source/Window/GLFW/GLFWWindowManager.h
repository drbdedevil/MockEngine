#pragma once

#include "Window/IWindow.h"
#include "Window/IWindowManager.h"

#include <memory>
#include <unordered_map>
#include <expected>

#include "Core/Utility.h"

namespace Mock
{
class GLFWWindowManager final : public IWindowManager, public NonCopyable
{
public:
    GLFWWindowManager();
    ~GLFWWindowManager() override;

    void update() override;
    bool areAllWindowsClosed() const override;

    std::expected<WindowId, WindowCreationError> createWindow(const WindowSettings& settings) override;
    std::shared_ptr<IWindow> getWindowById(WindowId id) const override;

private:
    std::unordered_map<WindowId, std::shared_ptr<IWindow>> m_windows;
    WindowId m_windowIdCounter{1};
    bool m_initialized{false};

    void cleanupClosedWindows();
};

} // namespace Mock