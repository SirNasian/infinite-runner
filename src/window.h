#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "renderer.h"

#include <iostream>

inline void framebuffer_size_callback(GLFWwindow* window, int width, int height);

inline GLFWwindow* InitWindow()
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

inline int DisplayWindow(GLFWwindow *window, Renderer *renderer)
{
	double time_delta = 0.0f;
	double time_last  = 0.0f;

	renderer->SetFPS(144);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		time_delta = glfwGetTime() - time_last;
		if (renderer->ShouldRender(time_delta))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			renderer->Render(time_delta);
			glfwSwapBuffers(window);
			time_last = glfwGetTime();
			std::cout << "RENDER (" << 1.0f / time_delta << " FPS)" << std::endl;
		};
		glfwPollEvents();
	};

	glfwTerminate();
	return 0;
};

inline void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
