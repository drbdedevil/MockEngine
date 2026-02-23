#include "GLFWWindow.h"

#include "Log/Log.h"
#include "GLFW/glfw3.h"

using namespace Mock;

DEFINE_LOG_CATEGORY_STATIC(LogGLFWWindow);

GLFWWindow::GLFWWindow() 
{
    m_window = glfwCreateWindow(900, 600, "MockEngine", nullptr, nullptr);
    if (!m_window)
    {
        M_LOG(LogGLFWWindow, Error, "Failed to create GLFW window!");
        return;
    }

    glfwSetWindowPos(m_window, 50, 50);
}

GLFWWindow::~GLFWWindow() 
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
}