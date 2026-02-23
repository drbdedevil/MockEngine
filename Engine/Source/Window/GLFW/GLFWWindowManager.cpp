#include "GLFWWindowManager.h"

#include "Log/Log.h"
#include "GLFWWindow.h"
#include "GLFW/glfw3.h"

using namespace Mock;

DEFINE_LOG_CATEGORY_STATIC(LogGLFWWindowManager);

GLFWWindowManager::GLFWWindowManager() 
{
    glfwSetErrorCallback([](int errorCode, const char* description) 
		{
			M_LOG(LogGLFWWindowManager, Error, "GLFW error, code: {}, description: {}", errorCode, description);
		});

	if (!glfwInit())
	{
        M_LOG(LogGLFWWindowManager, Error, "Failed to initialize GLFW!");
        return;
	}

	m_initialized = true;
    M_LOG(LogGLFWWindowManager, Display, "GLFW initialized successfully!");

	m_window = std::make_shared<GLFWWindow>();
}

GLFWWindowManager::~GLFWWindowManager() 
{
	if (m_initialized)
	{
        glfwTerminate();
	}

	m_initialized = false;
    M_LOG(LogGLFWWindowManager, Display, "GLFW shutdown!");
}