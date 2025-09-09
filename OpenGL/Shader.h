#ifndef SHADER_H
#define SHADER_H

#include "StandardIncludes.h"

class Shader
{
public:
	// Constructors / Destructors
	Shader();
	virtual ~Shader() { }

	// Accessors
	GLuint GetProgramID() { return m_programID; }
	GLuint GetAttrVertices() { return m_attrVertices; }

	// Methods
	void LoadShaders(const char* _vertexFilePath, const char* _fragementFilePath);
	void Cleanup();

private:
	// Methods
	void CreateShaderProgram(const char* _vertexFilePath, const char* _fragmentFilePath);	// ID of out shader program
	GLuint LoadShaderFile(const char* _filePath, GLenum _type);	// Handle for the attribute vertex buffer
	void LoadAttributes();
	void EvaulateShader(int _infoLength, GLuint _id);

	// Members
	GLuint m_programID;
	GLuint m_attrVertices;
	GLuint m_result = GL_FALSE;
	int m_infoLogLength;
};

#endif //SHADER_H