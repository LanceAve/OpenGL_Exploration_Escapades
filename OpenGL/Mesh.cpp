#include "Mesh.h"
#include "Shader.h"

Mesh::Mesh()
{
	m_shader = nullptr;
	m_vertexBuffer = 0;
}

Mesh::~Mesh()
{
}

// define what the create function does
void Mesh::Create(Shader* _shader) 
{
	m_shader = _shader;

	m_vertexData = { -1.0f, -1.0f, 0.0f,
					  1.0f, -1.0f, 0.0f,
					  0.0f,  1.0f, 0.0f };
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
void Mesh::Render()
{
	glUseProgram(m_shader->GetProgramID());	// use our shader instead of the built-in one
	
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(m_shader->GetAttrVertices(),		// The attribute we want to configure
		3,							// size
		GL_FLOAT,					// type
		GL_FALSE,					// normalized?
		0,							// stride
		(void*)0);					// array buffer offset
	
	// Draw the triangle !
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glDrawArrays(GL_TRIANGLES, 0, 3); //Starting from vertex 0; 3 vertices = triangle
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
}