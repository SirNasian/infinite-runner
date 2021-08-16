#pragma once
#include <GLFW/glfw3.h>
#include "renderer.h"

inline int displayWindow(Renderer renderer)
{
	GLFWwindow *window;
	double time_delta = 0.0f;
	double time_last  = 0.0f;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	};

	glfwMakeContextCurrent(window);

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
