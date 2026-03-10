#include "Core/Engine.h"
#include <cstdlib>
#include <memory>

#include "Window/GLFW/GLFWWindowManager.h"

int main()
{
    std::unique_ptr<Mock::GLFWWindowManager> windowManager = std::make_unique<Mock::GLFWWindowManager>();

    Mock::Engine engine = Mock::Engine(std::move(windowManager));
    engine.run();

	return EXIT_SUCCESS;
}