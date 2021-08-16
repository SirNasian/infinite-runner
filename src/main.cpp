#include <stdio.h>
#include "window.h"
#include "renderer.h"

int main(void)
{
	GLFWwindow *window = InitWindow();
	if (!window) return -1;
	Renderer renderer;
	return DisplayWindow(window, renderer);
};
