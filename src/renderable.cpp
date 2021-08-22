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
	this->SetSize(32.0f, 32.0f);
};

void Renderable::Render(glm::mat4 mat_view, glm::mat4 mat_projection)
{
	glUseProgram(this->GetShader()->GetProgram());
	this->UpdateModelUniform();
	this->UpdateViewUniform(mat_view);
	this->UpdateProjectionUniform(mat_projection);
	glBindVertexArray(this->vao);
	// TODO: consider defining a flexible number of vertices
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
};

void Renderable::UpdateModelUniform()
{
	glm::mat4 mat_model;
	unsigned int loc_model;
	mat_model = glm::mat4(1.0f);
	mat_model = glm::translate(mat_model, glm::vec3(this->GetPosX(), this->GetPosY(), 0.0f));
	mat_model = glm::scale(mat_model, glm::vec3(this->size_width, this->size_height, 0.0f));
	loc_model = glGetUniformLocation(this->GetShader()->GetProgram(), "uModel");
	// NOTE: this function assumes that `glUseProgram` has already been set
	glUniformMatrix4fv(loc_model, 1, GL_FALSE, glm::value_ptr(mat_model));
};

void Renderable::UpdateViewUniform(glm::mat4 mat_view)
{
	unsigned int loc_view;
	loc_view = glGetUniformLocation(this->GetShader()->GetProgram(), "uView");
	// NOTE: this function assumes that `glUseProgram` has already been set
	glUniformMatrix4fv(loc_view, 1, GL_FALSE, glm::value_ptr(mat_view));
};

void Renderable::UpdateProjectionUniform(glm::mat4 mat_projection)
{
	unsigned int loc_projection;
	loc_projection = glGetUniformLocation(this->GetShader()->GetProgram(), "uProjection");
	// NOTE: this function assumes that `glUseProgram` has already been set
	glUniformMatrix4fv(loc_projection, 1, GL_FALSE, glm::value_ptr(mat_projection));
};
