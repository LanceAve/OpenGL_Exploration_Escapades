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
	void Render(glm::mat4 _wvp);	// each mesh will have it's own projection
									// so that they don't overlap unto each other

private:
	Shader* m_shader;						// then define the variable
	GLuint m_vertexBuffer;					// stored in GPU buffer
	GLuint m_indexBuffer;					// store in GPU buffer
	vector<GLfloat> m_vertexData;			// store the vertex data in RAM
	vector<GLubyte> m_indexData;			// notice that it uses the GLubyte type (also index buffer gets stored in RAM as well)
	mat4 m_world;
};

#endif // MESH_H