#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "renderer.h"

#include <iostream>

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
	}

	return window;
};

inline int DisplayWindow(GLFWwindow *window, Renderer renderer)
{
	double time_delta = 0.0f;
	double time_last  = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		time_delta = glfwGetTime() - time_last;
		renderer.Render(time_delta);
		time_last = glfwGetTime();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
};
