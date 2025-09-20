#ifndef CAMERA_H
#define CAMERA_H

#include "..\OpenGL\StandardIncludes.h"

// define Camera class responsible for... well, camera functions
class Camera
{
public:
	// Constructors / Destructors
	Camera();
	Camera(Resolution _screenResolution);
	virtual ~Camera();

	// Accessors
	glm::mat4 GetProjection() { return m_projection; }
	glm::mat4 GetView() { return m_view; }

private:
	// Members
	glm::mat4 m_projection;
	glm::mat4 m_view;

};

#endif CAMERA_H	// CAMERA_H