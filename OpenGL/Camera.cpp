#include "Camera.h"

Camera::Camera()
{
	m_projection = { };
	m_view = { };
}

Camera::Camera(Resolution _screenResolution)
{
	/* Projection matrix specs:
		45° FoV
		4:3 aspect ration
		display range : 0.1 unit (100 units)
	*/ 
	// FYI: For regular projection.
	// Ortho below if you wanna muse that
	m_projection =
		glm::perspective(
			glm::radians(45.0f),
			(float)_screenResolution.m_width /
			(float)_screenResolution.m_height,
			0.1f,
			100.0f);

	// orthographic camera (for reference) :
	// glm::mat4 Projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	// \> this is in world coordinates though, that's why the numbers are so large

	// Camera matrix
	m_view = glm::lookAt(
		glm::vec3(4, 3, 3),		// Camera is set to (4, 3, 3) in World Space
		glm::vec3(0, 0, 0),		// and looks at the origin point
		glm::vec3(0, 1, 0)		// Then head is set to UP (you can set it to (0, -1, 0) to look upside down)
	);
}

Camera::~Camera() { }