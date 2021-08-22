#include <stdio.h>
#include "../include/Window.hpp"
#include "../include/Renderer.hpp"
#include "../include/Shader.hpp"

int main(void)
{
	GLFWwindow *window = InitWindow();
	if (!window) return -1;
	Renderer renderer;
	GameController controller(window, &renderer);
	return DisplayWindow(window, &controller);
};
