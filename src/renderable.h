#pragma once
#include "shader.h"

class Renderable
{
	private:
		unsigned int vao;
		unsigned int vbo;
		Shader *shader;
	public:
		Renderable(Shader *shader);
		Shader* GetShader() { return this->shader; };
		unsigned int GetVAO() { return this->vao; };
};
