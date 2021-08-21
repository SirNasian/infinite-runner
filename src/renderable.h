#pragma once
#include "shader.h"

class Renderable
{
	private:
		Shader *shader;
		unsigned int vao, vbo;
		float pos_x, pos_y;
		void UpdateModelUniform();
	public:
		Renderable(Shader *shader);
		Shader* GetShader() { return this->shader; };
		unsigned int GetVAO() { return this->vao; };
		float GetPosX() { return this->pos_x; };
		float GetPosY() { return this->pos_y; };
		void SetPos(float pos_x, float pos_y);
};
