#include <GL/glew.h>
#include "renderable.h"

Renderable::Renderable(Shader *shader)
{
	this->shader = shader;
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
};
