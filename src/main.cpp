#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "renderable.h"
#include "renderer.h"

int main(int argc, char **argv)
{
	if (!glfwInit())
	{
		printf("ERROR: Failed to initialise GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(400, 400, "infinite-runner", NULL, NULL);
	if (!window)
	{
		printf("ERROR: Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	GLenum glewErr = glewInit();
	if (glewErr != GLEW_OK)
	{
		printf("ERROR: Failed to initialise GLEW\n");
		return -1;
	}

	GLfloat a[] = {
		100.0f, 300.0f,
		300.0f, 300.0f,
		100.0f, 100.0f,
		300.0f, 100.0f,
	};

	GLuint b[] = {
		0, 1, 2,
		1, 2, 3,
	};

	Renderable *r1 = new Renderable(sizeof(a), a, sizeof(b), b, 6);
	Renderer ren;

	glViewport(0, 0, 400, 400);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ren.render(r1);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
