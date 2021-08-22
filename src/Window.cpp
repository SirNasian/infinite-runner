#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../include/GameController.hpp"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

GLFWwindow* InitWindow()
{
	GLFWwindow *window;
	if (!glfwInit()) return NULL;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return NULL;
	};

	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return NULL;
	};

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return window;
};

int DisplayWindow(GLFWwindow *window, GameController *controller)
{
	double time_delta_update = 0.0f;
	double time_delta_render = 0.0f;
	double time_last_update  = 0.0f;
	double time_last_render  = 0.0f;

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		time_delta_update = glfwGetTime() - time_last_update;
		controller->Update(time_delta_update);

		time_delta_render = glfwGetTime() - time_last_render;
		if (controller->GetRenderer()->ShouldRender(time_delta_render))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			controller->GetRenderer()->Render(time_delta_render);
			glfwSwapBuffers(window);
			time_last_render = glfwGetTime();
			std::cout << "RENDER (" << 1.0f / time_delta_render << " FPS)" << std::endl;
		};
		time_last_update = glfwGetTime();
		glfwPollEvents();
	};

	glfwTerminate();
	return 0;
};
