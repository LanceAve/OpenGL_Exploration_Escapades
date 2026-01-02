# Real-Time Rendering via OpenGL (C++)
A C++ project that makes use of OpenGL (3.3 core) that implements a real-time rendering pipeline,  including camera systems, texturing, lighting, instancing, font rendering, and post-processing effects.

## Features
- Core OpenGL rendering pipeline (VAOs, VBOs, shaders)
- Camera system with view and projection matrices
- Object transformations using linear algebra
- Texture mapping with layered textures (diffuse, specular)
- Phong lighting model (diffuse + specular)
- Light attenuation and multi-light scenes
- Correct normal mapping using tangent and bitangent space
- Multiple object rendering via instancing
- Font rendering
- Post-processing effects (grayscale, blur, edge detection)
- RGB to YUV color space conversion
- Mesh scale, rotation, and translation control via tool windows

## Build Notes
This project currently targets x86 Windows platforms and requires the following libraries:
-	stb image library
-	glew-2.1.0
-	glfw-3.3.4
-	glm
-	obj_loader
-	freetype-2.10.4

> **Note:** With libraries that contain version numbers, ensure that you adhere to those, since this project does not make use of the latest features found in modern OpenGL.

### Project Structure
This repository uses branches to isolate major milestones and features. Non-functional and experimental branches will be labelled with `_junk` and retained for future reference.  

A detailed overview is available here:
[**BRANCHES.md**](BRANCHES.md)

## License
This project is licensed under the MIT License. See [**LICENSE**](LICENSE.md) for more details.