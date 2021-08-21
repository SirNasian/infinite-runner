#include <stdio.h>
#include "window.h"
#include "renderer.h"
#include "shader.h"

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
