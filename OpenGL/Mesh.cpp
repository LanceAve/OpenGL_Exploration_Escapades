#include "Mesh.h"

Mesh::Mesh()
{
	m_vertexBuffer = 0;
}

Mesh::~Mesh()
{
}

// define what the create function does
void Mesh::Create() 
{
	m_vertexData = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};
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
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glVertexAttribPointer(
		0, 3 /*size*/,
		GL_FLOAT /*type*/,
		GL_FALSE /*normalized*/,
		0 /*stride*/,
		(void*)0 /*offset*/
		);
	
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); //Starting from vertex 0; 3 vertices = triangle
	glDisableVertexAttribArray(0);
}