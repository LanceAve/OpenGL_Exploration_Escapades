#include "Shader.h"
#include "StandardIncludes.h"

Shader::Shader()
{
	m_programID = 0;
	m_attrVertices = 0;
	m_attrColors = 0;
	m_attrNormals = 0;				// *NEW* normals to help calculate light
	m_attrTexCoords = 0;			// *NEW* texture coordinates
	m_attrWVP = 0;
	m_attrWVP = 0;
	m_result = GL_FALSE;
	m_infoLogLength = 0;
}

void Shader::LoadAttributes()
{
	m_attrVertices = glGetAttribLocation(m_programID, "vertices");		// Get a handle for the vertex buffer
	m_attrColors = glGetAttribLocation(m_programID, "colors");			// gonna get a handle for colors buffer now too
	m_attrNormals = glGetAttribLocation(m_programID, "normals");		// getting the normals as well
	m_attrTexCoords = glGetAttribLocation(m_programID, "texCoords");	// *NEW* Get a handle for the texCoords buffer
	m_attrWVP = glGetUniformLocation(m_programID, "WVP");				// Get a handle for the WVP matrix
}

void Shader::EvaluateShader(int _infoLength, GLuint _id)
{
	if (_infoLength > 0)
	{
		vector<char> errorMessage(_infoLength + 1);
		glGetShaderInfoLog(_id, _infoLength, NULL, &errorMessage[0]);
		M_ASSERT(0, ("%s\n", &errorMessage[0]));
	}
}
// sets a vec3 uniform variable in currently active shader program
void Shader::SetVec3(const char* _name, vec3 _value)
{
	// find location of uniform variable
	GLuint loc = glGetUniformLocation(m_programID, _name);
	
	// does it exist?
	if (loc != -1)
	{
		// upload value to that uniform location in GPU
		glUniform3fv(loc, 1, &_value[0]);
	}
}

void Shader::SetMat4(const char* _name, mat4 _value)
{
	GLuint loc = glGetUniformLocation(m_programID, _name);

	if (loc != -1)
	{
		glUniformMatrix4fv(loc, 1, GL_FALSE ,&_value[0][0]);
	}
}

void Shader::SetFloat(const char* _name, float _value)
{
	// find location of uniform variable
	GLuint loc = glGetUniformLocation(m_programID, _name);

	// does it exist?
	if (loc != -1)
	{
		// upload value to that uniform location in GPU
		glUniform1f(loc, _value);
	}
}

GLuint Shader::LoadShaderFile(const char* _filePath, GLenum _type)
{
	GLuint shaderID = glCreateShader(_type); // Create the shader 

	// Read the Shader code from the file
	string shaderCode;
	ifstream shaderStream(_filePath, std::ios::in);
	M_ASSERT(shaderStream.is_open(), ("Not possible to open %s. Are you sure you are in the correct directory? Please refer to the FAQ if you are having trouble !\n", _filePath));
	string Line = "";
	while (getline(shaderStream, Line))
		shaderCode += "\n" + Line;
	shaderStream.close();

	// Compile the Shader
	char const* sourcePointer = shaderCode.c_str();			// locate the shader pointer
	glShaderSource(shaderID, 1, &sourcePointer, NULL);
	glCompileShader(shaderID);

	// Sanity Check the Shader (in case it failed to compile)
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &m_result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &m_infoLogLength);
	EvaluateShader(m_infoLogLength, shaderID);

	// Attach the Shader to the program
	glAttachShader(m_programID, shaderID);

	return shaderID;
}

void Shader::CreateShaderProgram(const char* _vertexFilePath, const char* _fragmentFilePath)
{
	m_programID = glCreateProgram();													// Creat the shader program
	GLuint vertexShaderID = LoadShaderFile(_vertexFilePath, GL_VERTEX_SHADER);			// then load the vertex shader
	GLuint fragmentShaderID = LoadShaderFile(_fragmentFilePath, GL_FRAGMENT_SHADER);	// then load the fragment shader thingie
	glLinkProgram(m_programID);															// FInally link the program already

	// Check the program
	glGetProgramiv(m_programID, GL_LINK_STATUS, &m_result);
	glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &m_infoLogLength);
	EvaluateShader(m_infoLogLength, m_programID);
	
	// Free the resources we allocated
	glDetachShader(m_programID, vertexShaderID);
	glDetachShader(m_programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

void Shader::LoadShaders(const char* _vertexFilePath, const char* _fragmentFilePath)
{
	CreateShaderProgram(_vertexFilePath, _fragmentFilePath);
	LoadAttributes();
}

void Shader::Cleanup()
{
	glDeleteProgram(m_programID);
}