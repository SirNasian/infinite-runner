#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../include/GameController.hpp"
#include "../include/Renderable.hpp"
#include "../include/Renderer.hpp"
#include "../include/Shader.hpp"

#include <iostream>

GameController::GameController(GLFWwindow *window, Renderer *renderer)
{
	this->renderer = renderer;
	this->window   = window;

	// TODO: delete this block, this is just for testing
	{
		Shader *shader   = ConstructSimpleShader();
		Renderable *r1   = new Renderable(shader);
		Renderable *r2   = new Renderable(shader, r1->GetVAO());
		this->renderable = new Renderable(shader, r1->GetVAO());
		r1->SetPos(64.0f, 64.0f);
		r2->SetPos(256.0f, 256.0f);
		r2->SetSize(64.0f, 64.0f);
		this->renderable->SetSize(16.0f, 16.0f);
		this->renderer->RegisterRenderable(r1);
		this->renderer->RegisterRenderable(r2);
		this->renderer->RegisterRenderable(this->renderable);
	};
};

void GameController::Update(float time_delta)
{
	double cursor_real_x, cursor_real_y;
	int window_width, window_height;
	double cursor_virtual_x, cursor_virtual_y;
	glfwGetWindowSize(this->window, &window_width, &window_height);
	glfwGetCursorPos(this->window, &cursor_real_x, &cursor_real_y);
	cursor_virtual_x = (cursor_real_x / window_width) * this->renderer->GetViewWidth();
	cursor_virtual_y = (cursor_real_y / window_height) * this->renderer->GetViewHeight();
	std::cout << "(" << cursor_virtual_x << ", " << cursor_virtual_y << ")" << std::endl;
	this->renderable->SetPos(cursor_virtual_x, cursor_virtual_y);
};
