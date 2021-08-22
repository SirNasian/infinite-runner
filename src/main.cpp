#include <stdio.h>
#include "../include/window.hpp"
#include "../include/renderer.hpp"
#include "../include/shader.hpp"

int main(void)
{
	GLFWwindow *window = InitWindow();
	if (!window) return -1;
	Shader shader = ConstructSimpleShader();
	Renderable renderable(&shader);
	Renderer renderer;
	renderer.RegisterRenderable(&renderable);
	return DisplayWindow(window, &renderer);
};
