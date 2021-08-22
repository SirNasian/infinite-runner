#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../include/Renderer.hpp"

class GameController
{
	private:
		GLFWwindow *window;
		Renderer *renderer;
		Renderable *renderable; // TODO: delete this field, this is just for testing
	public:
		GameController(GLFWwindow *window, Renderer *renderer);
		Renderer* GetRenderer() { return renderer; };
		void Update(float time_delta);
};
