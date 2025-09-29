#include "WindowController.h"
#include "StandardIncludes.h"

// Initial method that defines WindowController
WindowController::WindowController()
{
	m_window = nullptr;
}

// Termination method that triggers if window does not exist
WindowController::~WindowController()
{
	if (m_window != nullptr)
	{
		glfwTerminate();
		m_window = nullptr;
	}
}

// Method responsible for rendering a new window
void WindowController::NewWindow()
{
	M_ASSERT(glfwInit(), "Failed to initialize GLFW.");	// Initialize GLFW

	// Open a window and create its OpenGL context
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	M_ASSERT((m_window = glfwCreateWindow(1024, 768, "A sample scene", NULL, NULL)) != nullptr, "Failed to open GLFW window.");
	glfwMakeContextCurrent(m_window);
}

// Method responsible for getting the resolution of the current active monitor
/*
* Note: If you are running a multi - monitor display, things may be a bit difficult
* Keep that in mind for the future.
*/ 
Resolution WindowController::GetResolution()
{
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	return Resolution(mode->width, mode->height);
}
