#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController()
{
	m_shaderColor = { };
	m_shaderDiffuse = { };
	m_camera = { };
	m_meshBox = { };
	m_meshLight = { };
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow();	// Must call this first, since it creates the window
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.");		// Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);				// Make sure that we can capture the escape key if it's pressed
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);								// Changed to Black backgroun now (can be deduced using art program)
	glEnable(GL_DEPTH_TEST);											// prevents face of mesh from being displayed on both sides


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
	m_meshLight = Mesh();
	m_meshLight.Create(&m_shaderColor);
	m_meshLight.SetPosition({ 1.0f, 0.5f, 0.5f });
	m_meshLight.SetScale({ 0.1f, 0.1f, 0.1f });

	m_meshBox = Mesh();
	m_meshBox.Create(&m_shaderDiffuse);
	m_meshBox.SetLightColor({ 0.5f, 0.9f, 0.5f });
	m_meshBox.SetLightPosition(m_meshLight.GetPosition());
	m_meshBox.SetCameraPosition(m_camera.GetPosition());

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);					// Clear the screen
		m_meshBox.Render(m_camera.GetProjection() * m_camera.GetView());	// add the projection system now so we have a camera
		m_meshLight.Render(m_camera.GetProjection() * m_camera.GetView());	// add the projection system now so we have a camera

		glfwSwapBuffers(WindowController::GetInstance().GetWindow());		// Swap the back and front buffers
		glfwPollEvents();

	} 
	while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&		// Check if the ESC key was pressed
			glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0);						// Check if the window was closed

	// memory cleaning portion
	m_meshLight.Cleanup();
	m_meshBox.Cleanup();
	m_shaderDiffuse.Cleanup();
	m_shaderColor.Cleanup();
}