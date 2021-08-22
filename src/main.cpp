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
	Renderable r1(&shader), r2(&shader, r1.GetVAO());
	r1.SetPos(64.0f, 64.0f);
	r2.SetPos(256.0f, 256.0f);
	r2.SetSize(64.0f, 64.0f);
	renderer.RegisterRenderable(&r1);
	renderer.RegisterRenderable(&r2);
	return DisplayWindow(window, &renderer);
};
