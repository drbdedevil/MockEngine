#include "Engine.h"

#include <format>
#include "Log/Log.h"
#include "Window/GLFW/GLFWWindowManager.h"

using namespace Mock;

DEFINE_LOG_CATEGORY_STATIC(LogEngine);

Engine::Engine()
{
    M_LOG(LogEngine, Display, "Yooo... Initializing MockEngine-v{}", version());

    m_windowManager = std::make_unique<GLFWWindowManager>();



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

    while (true)
    {

    }
}
