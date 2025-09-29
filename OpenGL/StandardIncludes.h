#ifndef STANDARD_INCLUDES_H
#define STANDARD_INCLUDES_H

// Include standard headers
#include <vector>
#include <string>
#include <fstream>

// Windows specific includes and defines
#ifdef _WIN32
#include <Windows.h>
#define M_ASSERT(_cond, _msg) \
	if (!(_cond)) { OutputDebugStringA(_msg); std::abort(); glfwTerminate(); }
#endif

// Open GL / Helper headers
#include <GL/glew.h>		// Include GLEW
#include <GLFW/glfw3.h>		// Include GLFW
#include <glm/glm.hpp>		// Include GLM
#include <glm/ext.hpp>		// OpenGL Experimental to_string (might be useful)
#include <glm/gtc/matrix_transform.hpp> // View / Projection

// User-made headers
#include "Resolution.h"
#include "Singleton.h"

// avoids redundant std:: and glm:: after every method call
using namespace std;
using namespace glm;

#endif //STANDARD_INCLUDES_H