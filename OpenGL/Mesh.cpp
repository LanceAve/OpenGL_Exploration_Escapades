#include "Mesh.h"
#include "Shader.h"

Mesh::Mesh()
{
	m_shader = nullptr;
	m_vertexBuffer = 0;
	m_world = glm::mat4(1.0f);
}

Mesh::~Mesh()
{
}

// define what the create function does
void Mesh::Create(Shader* _shader) 
{
	m_shader = _shader;

	m_vertexData = { 
		/*  Position  */  /*    RGBA Color    */
		0.2f, 0.2f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.3f, 0.9f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		0.4f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 
		0.7f, 0.8f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 
		0.8f, 0.4f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 
		1.0f, 0.6f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 
		1.0f, 0.2f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 
		1.5f, 0.6f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, };
	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);
}

// define what the cleanup function does (used to delete the mesh)
void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_vertexBuffer);
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
		3,								// size
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		0,								// stride
		(void*)0);						// array buffer offset
	
	_wvp *= m_world;
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, 3); // Draw the triangle !
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
}