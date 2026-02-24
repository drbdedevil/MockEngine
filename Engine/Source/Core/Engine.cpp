#include "Engine.h"

#include <format>
#include "Log/Log.h"
#include <format>
#include "Window/GLFW/GLFWWindowManager.h"

using namespace Mock;

DEFINE_LOG_CATEGORY_STATIC(LogEngine);

Engine::Engine()
{
    M_LOG(LogEngine, Display, "Yooo... Initializing MockEngine-v{}", version());

    m_windowManager = std::make_unique<GLFWWindowManager>();

    const auto windowResult = m_windowManager->createWindow(WindowSettings{});
    if (!windowResult)
    {
        M_LOG(LogEngine, Error, "Failed to create main window!");
        return;
    }

    if (std::shared_ptr<GLFWWindow> window = m_windowManager->getWindowById(windowResult.value()))
    {
        window->setTitle(std::format("MockEngine v{}", version()));
    }

    m_initialized = true;
}

Mock::Engine::~Engine() {}

void Engine::run() 
{
    if (!m_initialized)
    {
        M_LOG(LogEngine, Error, "Cannot run: MockEngine is not initialized...");
        return;
    }

    while (!m_windowManager->areAllWindowsClosed())
    {
        m_windowManager->update();
    }
}
