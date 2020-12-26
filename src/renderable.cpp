#include <SOIL/SOIL.h>

#include "renderable.h"

Renderable::Renderable(const GLsizeiptr bufferSize, const GLfloat *bufferData, const GLsizeiptr elementSize,
	const GLuint *elementData, const int elementCount, const char* texturePath)
{
	glGenVertexArrays(1, &(this->_vao));
	glBindVertexArray(this->_vao);

	glGenBuffers(1, &(this->_vbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW);

	glGenBuffers(1, &(this->_ebo));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementSize, elementData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4*sizeof(GLfloat), (const GLvoid*)(0*sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4*sizeof(GLfloat), (const GLvoid*)(2*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	this->_tex = 0;
	GLsizei textureWidth, textureHeight, textureChannels;
	GLvoid *textureData = SOIL_load_image(texturePath, &textureWidth, &textureHeight, &textureChannels, SOIL_LOAD_RGBA);
	if (textureData)
	{
		glGenTextures(1, &(this->_tex));
		glBindTexture(GL_TEXTURE_2D, this->_tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

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

int Renderable::getTEX()
{
	return this->_tex;
}

