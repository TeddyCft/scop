#include "scop.hpp"
#include <iostream>
#include <GLFW/glfw3.h>

int main()
{
	GLFWwindow* window;

    if (!glfwInit())
	{
		std::cout << "failure to start GLFW." << std::endl;
		return 1;
	}

	window = glfwCreateWindow(640, 480, "New Window", NULL, NULL);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	glfwTerminate();
	std::cout << "done" << std::endl;
    return 0;
}