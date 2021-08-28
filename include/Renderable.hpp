#pragma once
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "./Shader.hpp"

class Renderable
{
	private:
		Shader *shader;
		unsigned int vao, vbo;
		float pos_x, pos_y, size_width, size_height;
		glm::mat4 CalculateModelMatrix();
	public:
		Renderable(Shader *shader, unsigned int vao = -1);
		Shader* GetShader() { return this->shader; };
		unsigned int GetVAO() { return this->vao; };
		float GetPosX() { return this->pos_x; };
		float GetPosY() { return this->pos_y; };
		void SetPos(float pos_x, float pos_y) { this->pos_x = pos_x; this->pos_y = pos_y; };
		void SetSize(float size_width, float size_height) { this->size_width = size_width; this->size_height = size_height; };
		void Render(glm::mat4 mat_view, glm::mat4 mat_projection);
};
