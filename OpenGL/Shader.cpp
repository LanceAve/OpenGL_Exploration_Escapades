#include "shader.h"
using 

Shader::Shader()
{
	m_programID = 0;
	m_attrVertices = 0;
	m_result = GL_FALSE;
	m_infoLogLength = 0;
}

void Shader::Cleanup()
{
	glDeleteProgram(m_programID);
}

void Shader::LoadAttributes()
{
	m_attrVertices = glGetAttribLocation(m_programID, "vertices"); // Get a handle for the vertex buffer
}

void Shader::EvaluateShader(int _infoLength, GLuint _id)
{
	if (_infoLength > 0)
	{
		std::vector<char> errorMessage(_infoLength + 1);
		glGetShaderInfoLog(_id, _infoLength, NULL, &errorMessage[0]);
		M_ASSERT(0, ("%s\n", &errorMessage[0]));
	}
}