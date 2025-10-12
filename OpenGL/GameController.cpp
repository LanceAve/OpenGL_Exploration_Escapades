#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController()
{
	m_shader = { };
	m_camera = { };
	m_mesh = { };
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow();	// Must call this first, since it creates the window
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.");		// Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);				// Make sure that we can capture the escape key if it's pressed
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);								// Changed to Black backgroun now (can be deduced using art program)
	glEnable(GL_CULL_FACE);												// prevents face of mesh from being displayed on both sides


	// Create the default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame()
{
	// Show the C++/CLI tool window
	PrimitiveDrawTest::ToolWindow^ window = gcnew PrimitiveDrawTest::ToolWindow();
	window->Show();

	// Create and compile our GLSL program from the shaders
	m_shader = Shader();
	m_shader.LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentShader");
	
	m_mesh = Mesh();
	m_mesh.Create(&m_shader);

	do
	{
		System::Windows::Forms::Application::DoEvents();	// Handle C++/CLI form events
		
		// Convert 0..200 slider to 0.0..2.0 multiplier for shader
		GLfloat yScale = PrimitiveDrawTest::ToolWindow::YValue / 100.0f;
		GLfloat uScale = PrimitiveDrawTest::ToolWindow::UValue / 100.0f;
		GLfloat vScale = PrimitiveDrawTest::ToolWindow::VValue / 100.0f;
		GLint loc;

		// set Yscale
		loc = glGetUniformLocation(m_shader.GetProgramID(), "Yscale");
		glUniform1f(loc, yScale);

		// set Uscale
		loc = glGetUniformLocation(m_shader.GetProgramID(), "Uscale");
		glUniform1f(loc, uScale);

		// set Vscale
		loc = glGetUniformLocation(m_shader.GetProgramID(), "Vscale");
		glUniform1f(loc, vScale);

		// set invert bool
		loc = glGetUniformLocation(m_shader.GetProgramID(), "InvertColors");
		glUniform1i(loc, PrimitiveDrawTest::ToolWindow::InvertColors ? 1 : 0);

		glClear(GL_COLOR_BUFFER_BIT);									// Clear the screen
		m_mesh.Render(m_camera.GetProjection() * m_camera.GetView());	// add the projection system now so we have a camera
		glfwSwapBuffers(WindowController::GetInstance().GetWindow());	// Swap the back and front buffers
		glfwPollEvents();

	} 
	while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&		// Check if the ESC key was pressed
			glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0);						// Check if the window was closed

	// memory cleaning process
	m_mesh.Cleanup();
	m_shader.Cleanup();
}