#include "Mesh.h"
#include "Shader.h"
#include "StandardIncludes.h"

Mesh::Mesh()
{
	// shader related
	m_shader = nullptr;

	// texture related
	m_texture = { };
	m_texture2 = { };

	// buffer related
	m_vertexBuffer = 0;
	m_indexBuffer = 0;

	// transformation and scale
	m_position = { 0, 0, 0, };
	m_rotation = { 0, 0, 0 };
	m_scale = { 1, 1, 1 };
	m_world = mat4();

	// light related
	m_lightPosition = { 0, 0, 0 };
	m_lightColor = { 1, 1, 1 };		// default to white for now

}

Mesh::~Mesh() { }

// define what the create function does
void Mesh::Create(Shader* _shader) 
{
	m_shader = _shader;

	// Copy texture to Solution/Assets/Texture folder
	m_texture = Texture();
	m_texture.LoadTexture("../Assets/Textures/Wood.jpg");

	// finally, we do the forbidden and layer two textures onto each other
	m_texture2 = Texture();
	m_texture2.LoadTexture("../Assets/Textures/Emoji.jpg");
	
	// Good source for float colors (wowzers!)
	// https://prideout.net/blog/old/archive/colors.php.html#Floats

	// changing shape to a cube now! (hidden so it doesn't take too much space.)
	#pragma region VertexData
	m_vertexData = 
	{
		/*    Position    */  /*    Normals    */  /* Texture Coords */
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
	};
	#pragma endregion
	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);
}

// define what the cleanup function does (used for garbage collection)
void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_vertexBuffer);
	m_texture.Cleanup();
	m_texture2.Cleanup();					// gotta clean up that text2 babe
}

// this time define what the Render function does
// and define the world view stuff
void Mesh::BindAttributes()
{	
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(
		m_shader->GetAttrVertices(),	// The attribute we want to configure
		3,								// size (now to render the vertices. 3 vertex per primitive)
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		8 * sizeof(float),				// stride (8 floats now per vertex definition)
		(void*)0);						// array buffer offset

	// 2nd attribute buffer : normals
	glEnableVertexAttribArray(m_shader->GetAttrNormals());
	glVertexAttribPointer(
		m_shader->GetAttrNormals(),		// The attribute we want to configure
		3,								// size (modified to 3 now)
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		8 * sizeof(float),				// stride (now modified to 8 floats per vertex def)
		(void*)(3 * sizeof(float)));	// array buffer offset

	// 3rd attribute buffer : texCoords
	glEnableVertexAttribArray(m_shader->GetAttrTexCoords());
	glVertexAttribPointer(
		m_shader->GetAttrTexCoords(),	// The attribute we want to configure
		2,								// size (acounts for the x and y coordinates)
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		8 * sizeof(float),				// stride (now modified to 8 floats per vertex def)
		(void*)(6 * sizeof(float)));	// array buffer offset
	
	// Bind vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	// binding texture one to texture unit 0 (up to 16 in OpenGL)
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture.GetTexture());	// Bind the texture now too
	glUniform1i(m_shader->GetSampler1(), 0);

	// bind texture two to be layered on texture 1
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_texture2.GetTexture());	// Bind the texture now too
	glUniform1i(m_shader->GetSampler2(), 1);				// notice how it's 1 now.
}

void Mesh::CalculateTransform()
{
	m_world = translate(mat4(1.0f), m_position);
	m_world = rotate(m_world, m_rotation.y, vec3(0, 1, 0));
	m_world = scale(m_world, m_scale);
}

void Mesh::SetShaderVariables(mat4 _pv)
{
	// World
	m_shader->SetMat4("WVP", _pv * m_world);
	m_shader->SetMat4("World", m_world);

	// Mesh
	m_shader->SetVec3("DiffuseColor", { 1.0f, 1.0f, 1.0f });
	
	// Lighting
	m_shader->SetVec3("AmbientLight", { 0.1f, 0.1f, 0.1f });
	m_shader->SetVec3("LightPosition", m_lightPosition);
	m_shader->SetVec3("LightColor", m_lightColor);
	
	// Specular
	m_shader->SetFloat("SpecularStrength", 4);
	m_shader->SetVec3("SpecularColor", { 3.0f, 3.0f, 3.0f });

	// Camera
	m_shader->SetVec3("CameraPosition", m_cameraPosition);
}

void Mesh::Render(mat4 _pv)
{
	glUseProgram(m_shader->GetProgramID());

	m_rotation.y += 0.0008f;

	CalculateTransform();
	SetShaderVariables(_pv);
	BindAttributes();

	// draw a triangle element
	GLsizei vertexCount = m_vertexData.size() / 8;
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);

	// turn off normal, vertex and texture coordinate data after draw call
	glDisableVertexAttribArray(m_shader->GetAttrNormals());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrTexCoords());
}