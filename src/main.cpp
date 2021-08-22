#include <stdio.h>
#include "../include/window.hpp"
#include "../include/renderer.hpp"
#include "../include/shader.hpp"

#include <iostream>

int main(void)
{
	GLFWwindow *window = InitWindow();
	if (!window) return -1;
	Shader shader = ConstructSimpleShader();
	Renderer renderer;
	Renderable r(&shader);
	for (int c = 0; c < 20000; c++)
	{
		renderer.RegisterRenderable(new Renderable(&shader, r.GetVAO()));
		std::cout << c+1 << std::endl;
	}
	return DisplayWindow(window, &renderer);
};
