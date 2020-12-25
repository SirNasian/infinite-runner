#pragma once

#include <GL/glew.h>

class Renderable
{
private:
	GLuint _vao;
	GLuint _vbo;
	GLuint _ebo;
	int _elementCount;
public:
	Renderable(const GLsizeiptr bufferSize, const GLfloat *bufferData, const GLsizeiptr elementSize, const GLuint *elementData, const int elementCount);
	void setVertexData(const GLsizeiptr size, const GLfloat *data);
	void setElementData(const GLsizeiptr size, const GLuint *data);
	int getElementCount();
	int getVAO();
};
