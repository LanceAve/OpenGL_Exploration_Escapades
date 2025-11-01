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
	GLuint GetAttrColors() { return m_attrColors; }			// adding color accessor now
	GLuint GetAttrNormals() { return m_attrNormals; }		// accessor for the normals
	GLuint GetAttrTexCoords() { return m_attrTexCoords; }	// accessor for texture coordinates
	GLuint GetAttrWVP() { return m_attrWVP; }				// allow access to WVP

	// Methods
	void LoadShaders(const char* _vertexFilePath, const char* _fragementFilePath);
	void Cleanup();
	void SetTextureSampler(const char* _name, GLuint _texUnit, int _texUnitID, int _value);
	void SetFloat(const char* _name, float _value);
	void SetVec3(const char* _name, vec3 _value);
	void SetMat4(const char* _name, mat4 _value);
	
private:
	// Methods
	void CreateShaderProgram(const char* _vertexFilePath, const char* _fragmentFilePath);	// ID of our shader program
	GLuint LoadShaderFile(const char* _filePath, GLenum _type);								// Handle for the attribute vertex buffer
	void LoadAttributes();
	void EvaluateShader(int _infoLength, GLuint _id);

	// Members
	GLuint m_programID;				// ID of our shader program
	GLuint m_attrVertices;			// Handle for the attribute vertex buffer
	GLuint m_attrColors;			// Color attribute now sick
	GLuint m_attrNormals;			// Normals attribute
	GLuint m_attrTexCoords;			// adding in texture coordinates member now
	GLuint m_attrWVP;
	GLint m_result = GL_FALSE;
	int	m_infoLogLength;
};

#endif //SHADER_H