#include "Mesh.h"
#include "Shader.h"

// avoids redundant glm:: & std after every method call
using namespace glm;

Mesh::Mesh()
{
	m_shader = nullptr;
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_world = mat4(1.0f);
}

Mesh::~Mesh()
{
}

// define what the create function does
void Mesh::Create(Shader* _shader) 
{
	m_shader = _shader;

	// Good source for float colors (wowzers!)
	// https://prideout.net/blog/old/archive/colors.php.html#Floats
	float a = 26.0f;
	float b = 42.0f;
	m_vertexData = { 
		/*   Position    */ /*       RGBA Color        */
	   -a,     0.0f,  b,	1.0f,	0.0f,	0.0f,	1.0f,	// Red
		a,     0.0f,  b,	1.0f,	0.549f, 0.0f,	1.0f,	// Orange
	   -a,     0.0f, -b,	1.0f,	1.0f,	0.0f,	1.0f,	// Yellow
		a,     0.0f, -b,	0.0f,	0.502f,	0.0f,	1.0f,	// Green
		0.0f,  b,	  a,	0.0f,	0.0f,	1.0f,	1.0f,	// Blue
		0.0f,  b,    -a,	0.294f, 0.0f,	0.51f,	1.0f,	// Indigo
		0.0f, -b,     a,	0.502f, 0.0f,	0.502f, 1.0f,	// Purple
		0.0f, -b,    -a,	1.0f,	1.0f,	1.0f,	1.0f,	// White
		b,     a,	  0.0f, 0.0f,	1.0f,	1.0f,	1.0f,	// Cyan
	   -b,     a,	  0.0f, 0.0f,	0.0f,	0.0f,	1.0f,	// Black
		b,    -a,     0.0f,	0.118f,	0.565f,	1.0f,	1.0f,	// Dodger Blue
	   -b,    -a,	  0.0f, 0.863f, 0.078f, 0.235f, 1.0f,	// Crimson
	};	
	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

	// adding the index data as well
	m_indexData = {
		0, 6,  1, 0, 11, 6, 1, 4,  0, 1, 8,  4,
		1, 10, 8, 2, 5,  3, 2, 9,  5, 2, 11, 9,
		3, 7,  2, 3, 10, 7, 4, 8,  5, 4, 9,  0,
		5, 8,  3, 5, 9,  4, 6, 10, 1, 6, 11, 7,
		7, 10, 6, 7, 11, 2, 8, 10, 3, 9, 11, 0
	};
	glGenBuffers(1, &m_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexData.size() * sizeof(GLubyte), m_indexData.data(), GL_STATIC_DRAW);
}

// define what the cleanup function does (used to delete the mesh)
void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteBuffers(1, &m_indexBuffer);
}

// this time define what the Render function does
// and define the world view stuff
void Mesh::Render(glm::mat4 _wvp)
{
	glUseProgram(m_shader->GetProgramID());	// use our shader instead of the built-in one
	
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(
		m_shader->GetAttrVertices(),	// The attribute we want to configure
		3,								// size (now to render the vertices. 3 vertex per primitive)
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		7 * sizeof(float),				// stride (7 floats now per vertex definition)
		(void*)0);						// array buffer offset

	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(m_shader->GetAttrColors());
	glVertexAttribPointer(
		m_shader->GetAttrColors(),		// The attribute we want to configure
		4,								// size (now includes color value)
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		7 * sizeof(float),				// stride (now modified)
		(void*)(3 * sizeof(float)));	// array buffer offset
	
	// 3rd attribute : WVP (World-View-Projection)
	m_world = rotate(m_world, 0.001f, { 0, 1, 0 });		// rotate the world by 1 on the y axis
	_wvp *= m_world;
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);
	
	// Bind both the vertex and index to reduce memory use
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer); 

	// draw elements rather than arrays
	glDrawElements(GL_TRIANGLES, m_indexData.size(), GL_UNSIGNED_BYTE, (void*)0);
	
	//glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size() / 7);		// Draw the triangle, but include the vertexData as well now
	//				  \-> primitive can be changed to draw different objects (e.g. GL_LINES) 
	glDisableVertexAttribArray(m_shader->GetAttrColors());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
}