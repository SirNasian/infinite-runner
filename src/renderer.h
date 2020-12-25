#pragma once

#include "renderable.h"

class Renderer
{
private:
	GLuint _shaderProgram;
	GLuint _viewUniform;
	GLuint _projectionUniform;
	GLuint createShaderProgram();
public:
	Renderer();
	void render(Renderable *renderable);
};
