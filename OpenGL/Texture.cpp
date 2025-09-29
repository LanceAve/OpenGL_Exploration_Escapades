#include "Texture.h"
#include "StandardIncludes.h"

// STB-related Includes (for texturing)
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Initialize members of Texture class
Texture::Texture()
{
	m_width = 0;
	m_height = 0;
	m_channels = 0;
	m_texture = 0;
}

// Garbage collection after program terminates
void Texture::Cleanup()
{
	glDeleteTextures(1, &m_texture);
}


// Load texture from filename
void Texture::LoadTexture(string _fileName)
{
	glGenTextures(1, &m_texture);				// Generate texture names
	glBindTexture(GL_TEXTURE_2D, m_texture);	// Bind named texture to texture unit

	// Set texture wrapping/filtering options (on the now-bound texture)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);					// repeat texture in S (x-axis) direction	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);					// repeat texture in T (x-axis) direction	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // use smooth filtering + mipmaps when minifying
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);				// use smooth filtering when magnifying

	// Load and generate the texture
	GLubyte* data = stbi_load(_fileName.c_str(), &m_width, &m_height, &m_channels, 0);	

	// load image file into RAM, get width/height/channels
	M_ASSERT(data != nullptr, "Failed to load texture from file");									// crash (or halt execution) if load fails
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);	// upload image data to GPU as 2D texture
	glGenerateMipmap(GL_TEXTURE_2D);																// generate mipmaps from base texture

	// Free image data from RAM afterwards
	stbi_image_free(data);
}

