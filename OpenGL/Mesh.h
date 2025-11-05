#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
#include "Texture.h"

class Shader;

class Mesh
{
public:
	// Constructors / Destructors
	Mesh();
	virtual ~Mesh();

	// Methods
	void Create(Shader* _shader);	// now we add shader in the mix
	void Cleanup();
									// so that they don't overlap unto each other
	void CalculateTransform();
	void Render(mat4 _pv);			// each mesh will have it's own projection

	// Accessors

	// getters and setters for position and scale
	void SetPosition(vec3 _position) { m_position = _position; }
	vec3 GetPosition() { return m_position; }
	void SetScale(vec3 _scale) { m_scale = _scale; }
	void SetColor(vec3 _color) { m_color = _color; }
	vec3 GetColor() { return m_color; }

	// setter for lighting position and lighting color
	void SetLightPosition(vec3 _lightPosition) { m_lightPosition = _lightPosition; }
	void SetLightColor(vec3 _lightColor) { m_lightColor = _lightColor; }

	// Camera
	void SetCameraPosition(vec3 _cameraPosition) { m_cameraPosition = _cameraPosition; }

private:

	// Private Methods
	void SetShaderVariables(mat4 _pv);
	void BindAttributes();

	// Member Variables
	Shader* m_shader;						// then define the variable
	Texture m_texture_diff;					// changed texture from being generic to diffuse
	Texture m_texture_spec;					// specular texture
	GLuint m_vertexBuffer;					// stored in GPU buffer
	GLuint m_indexBuffer;					// store in GPU buffer
	vector<GLfloat> m_vertexData;			// store the vertex data in RAM
	vector<GLubyte> m_indexData;			// notice that it uses the GLubyte type (also index buffer gets stored in RAM)

	// Transformation (scale, position)
	vec3 m_position;
	vec3 m_rotation;
	vec3 m_scale;
	mat4 m_world;
	vec3 m_color;

	// Lighting
	vec3 m_lightPosition;
	vec3 m_lightColor;

	// Camera
	vec3 m_cameraPosition;
};

#endif // MESH_H