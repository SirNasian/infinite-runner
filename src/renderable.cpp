#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../include/renderable.hpp"
#include "../include/shader.hpp"

Renderable::Renderable(Shader *shader, unsigned int vao)
{
	this->shader = shader;
	this->vao = vao;
	if (vao == -1)
	{
		// TODO: consider more flexible shapes than a simple square
		const float vertex_data[] = {
			-1.0f, -1.0f,
			-1.0f,  1.0f,
			 1.0f, -1.0f,
			 1.0f,  1.0f,
		};
		glGenVertexArrays(1, &(this->vao));
		glGenBuffers(1, &(this->vbo));
		glBindVertexArray(this->vao);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	}
	this->SetPos(0.0f, 0.0f);
};

void Renderable::SetPos(float pos_x, float pos_y)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
};

void Renderable::Render()
{
	glUseProgram(this->GetShader()->GetProgram());
	this->UpdateModelUniform();
	glBindVertexArray(this->vao);
	// TODO: consider defining a flexible number of vertices
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
};

void Renderable::UpdateModelUniform()
{
	glm::mat4 mat_model;
	unsigned int loc_model;
	mat_model = glm::translate(glm::mat4(1.0f), glm::vec3(this->GetPosX(), this->GetPosY(), 0.0f));
	loc_model = glGetUniformLocation(this->GetShader()->GetProgram(), "uModel");
	// NOTE: this function assumes that `glUseProgram` has already been set
	glUniformMatrix4fv(loc_model, 1, GL_FALSE, glm::value_ptr(mat_model));
};
