#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController()
{
	m_shaderColor = { };
	m_shaderDiffuse = { };
	m_camera = { };
	m_meshBoxes.clear();
	m_meshLight = { };
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow();	// Must call this first, since it creates the window
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.");		// Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);				// Make sure that we can capture the escape key if it's pressed
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);								// Changed to a grey background now
	glEnable(GL_DEPTH_TEST);											// prevents face of mesh from being displayed on both sides
	srand(time(0));


	// Create the default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame()
{
	// Create and compile our GLSL program from the shaders
	// Color
	m_shaderColor = Shader();
	m_shaderColor.LoadShaders("Color.vertexshader", "Color.fragmentShader");

	// Diffuse
	m_shaderDiffuse = Shader();
	m_shaderDiffuse.LoadShaders("Diffuse.vertexshader", "Diffuse.fragmentShader");
	
	// Mesh creation
	// doing the same thing that was done with the cube line, but with the ligths this time
	for (int count = 0; count < 4; count++)
	{
		m_meshLight = Mesh();
		m_meshLight.Create(&m_shaderColor);
		m_meshLight.SetPosition({ 0.5f + (float)count / 10.0f, 0.0f, -0.5f });
		m_meshLight.SetColor({ linearRand(0.0f, 1.0f), linearRand(0.0f, 1.0f), linearRand(0.0f, 1.0f) });
		m_meshLight.SetScale({ 0.1f, 0.1f, 0.1f });
		Mesh::Lights.push_back(m_meshLight);
	}

	// modifying the for loop such that it creates a wall of cubes rather than spawning them randomly
	for (int col = 0; col < 10; col++)
	{
		for (int count = 0; count < 10; count++)
		{
			Mesh box = Mesh();
			box.Create(&m_shaderDiffuse);
			box.SetLightColor({ 1.0f, 1.0f, 1.0f });
			box.SetLightPosition(m_meshLight.GetPosition());
			box.SetCameraPosition(m_camera.GetPosition());
			box.SetScale({ 0.1f, 0.1f, 0.1f });
			box.SetPosition({ 0.0f, -0.5f + (float)count / 10.0f, -0.2f + (float)col / 10.0f });
			m_meshBoxes.push_back(box);
		}
	}

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);								// Clear the screen
		for (unsigned int count = 0; count < m_meshBoxes.size(); count++)
		{
			m_meshBoxes[count].Render(m_camera.GetProjection() * m_camera.GetView());	// render all cube meshes
		}
		
		for (unsigned int count = 0; count < Mesh::Lights.size(); count++)
		{
			Mesh::Lights[count].Render(m_camera.GetProjection() * m_camera.GetView());	// render all cube meshes
		}

		glfwSwapBuffers(WindowController::GetInstance().GetWindow());					// Swap the back and front buffers
		glfwPollEvents();

	} 
	while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&		// Check if the ESC key was pressed
			glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0);						// Check if the window was closed

	// must cleanup every light cube spawned as well
	for (unsigned int count = 0; count < Mesh::Lights.size(); count++)
	{
		Mesh::Lights[count].Cleanup();
	}
	
	// must cleanup every cube spawned
	for (unsigned int count = 0; count < m_meshBoxes.size(); count++)
	{
		m_meshBoxes[count].Cleanup();
	}
	m_shaderDiffuse.Cleanup();
	m_shaderColor.Cleanup();
}