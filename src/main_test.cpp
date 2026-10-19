#include "scop.hpp"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

static const char* vertexShaderSource = R"(
#version 330 core

layout (location = 0) in vec3 aPos;

void main()
{
	gl_Position = vec4(aPos, 1.0);
}
)";

static const char* fragmentShaderSource = R"(
#version 330 core
uniform vec4 triangleColor;
out vec4 FragColor;
void main()
{
	FragColor = triangleColor;
}
)";

static GLuint compileShader(GLenum type, const char* source)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char log[512];
		glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
		std::cerr << "Shader compilation error:\n" << log << '\n';
	}
	return shader;
}

int main()
{
	GLFWwindow* window; // create a window variable

    if (!glfwInit()) // initiating glfwd
	{
		std::cout << "failure to start GLFW." << std::endl;
		return 1;
	} 

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "New Window", NULL, NULL); //set window values

	if (!window)
	{
		glfwTerminate();
		return (1);
	}

	glfwMakeContextCurrent(window); // creating glad context

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // load glad context
	{
		glfwTerminate();
		glfwDestroyWindow(window);
		return 1;
	}

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	GLuint VAO;
	GLuint VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(vertices),
		vertices,
		GL_STATIC_DRAW
	);
	
	glVertexAttribPointer(
		0, 3, GL_FLOAT, GL_FALSE,
		3 * sizeof(float), (void*)0
	);
	glEnableVertexAttribArray(0);
	GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	GLint success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	
	float red = 0.0f;

	GLint colorLocation = glGetUniformLocation(shaderProgram, "triangleColor");
	while (!glfwWindowShouldClose(window)) // waiting for close event
	{
		glUniform4f(colorLocation, red, 0.0f, 0.0f, 1.0f);
		red += 0.01f;
		if (red > 1.0f)
			red = 0.0f;
		glClearColor(red, 1.0f, 0.25f, 1.0f); // creating a color
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window); // ???
		glfwPollEvents(); // hoooking events
	}

	glfwTerminate(); // terminating opengl window
	std::cout << "done" << std::endl;
    return 0;
}