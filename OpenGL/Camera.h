#ifndef CAMERA_H
#define CAMERA_H

#include "StandardIncludes.h"

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
	vec3 GetPosition() { return m_position; }

private:
	// Members
	mat4 m_projection;
	mat4 m_view;
	vec3 m_position;

};

#endif CAMERA_H	// CAMERA_H