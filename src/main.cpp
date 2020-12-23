#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

	GLFWwindow *window = glfwCreateWindow(800, 600, "infinite-runner", NULL, NULL);
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

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
