#ifndef CAMERA_H
#define CAMERA_H

#include "..\OpenGL\StandardIncludes.h"
// avoids redundant std:: after every method call
using namespace glm;

// define Camera class responsible for... well, camera functions
class Camera
{
public:
	// Constructors / Destructors
	Camera();
	Camera(Resolution _screenResolution);
	virtual ~Camera();

	// Accessors
	mat4 GetProjection() { return m_projection; }
	mat4 GetView() { return m_view; }

private:
	// Members
	mat4 m_projection;
	mat4 m_view;

};

#endif CAMERA_H	// CAMERA_H