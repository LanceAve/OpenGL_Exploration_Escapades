#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
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
	void Render(glm::mat4 _wvp);	// each mesh will have it's own projection
									// so that they don't overlap unto each other

private:
	Shader* m_shader;	// then define the variable
	GLuint m_vertexBuffer;
	std::vector<GLfloat> m_vertexData;
	glm::mat4 m_world;
};

#endif // MESH_H