#include "Mesh.h"
#include "Shader.h"
#include "StandardIncludes.h"

Mesh::Mesh()
{
	// shader related
	m_shader = nullptr;

	// texture related
	m_texture_diff = { };
	m_texture_spec = { };

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

	// Copy diffuse texture to Solution/Assets/Texture folder
	m_texture_diff = Texture();
	m_texture_diff.LoadTexture("../Assets/Textures/crate_diffuse.jpg");

	// Now also copy the specular texture to the folder
	m_texture_spec = Texture();
	m_texture_spec.LoadTexture("../Assets/Textures/crate_specular.jpg");
	
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
	m_texture_diff.Cleanup();
	m_texture_spec.Cleanup();					// gotta clean up that text2 babe
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

	// Camera
	m_shader->SetVec3("CameraPosition", m_cameraPosition);
	
	// Lighting
	m_shader->SetVec3("light.position", m_lightPosition);
	m_shader->SetVec3("light.color", m_lightColor);
	m_shader->SetVec3("light.ambientColor", { 0.1f, 0.1f, 0.1f });
	m_shader->SetVec3("light.diffuseColor", { 1.0f, 1.0f, 1.0f });
	m_shader->SetVec3("light.specularColor", { 3.0f, 3.0f, 3.0f });

	// Mesh Material
	m_shader->SetFloat("material.specularStrength", 8);
	m_shader->SetTextureSampler("material.diffuseTexture", GL_TEXTURE0, 0, m_texture_diff.GetTexture());
	m_shader->SetTextureSampler("material.specularTexture", GL_TEXTURE1, 1, m_texture_spec.GetTexture());
}

void Mesh::Render(mat4 _pv)
{
	// use our custom shader
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