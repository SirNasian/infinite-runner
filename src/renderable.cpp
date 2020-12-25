#include "renderable.h"

Renderable::Renderable(const GLsizeiptr bufferSize, const GLfloat *bufferData, const GLsizeiptr elementSize,
	const GLuint *elementData, const int elementCount)
{
	glGenVertexArrays(1, &(this->_vao));
	glBindVertexArray(this->_vao);

	glGenBuffers(1, &(this->_vbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW);

	glGenBuffers(1, &(this->_ebo));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementSize, elementData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), (const GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	this->_elementCount = elementCount;
}

void Renderable::setVertexData(const GLsizeiptr size, const GLfloat *data)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderable::setElementData(const GLsizeiptr size, const GLuint *data)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int Renderable::getElementCount()
{
	return this->_elementCount;
}

int Renderable::getVAO()
{
	return this->_vao;
}
