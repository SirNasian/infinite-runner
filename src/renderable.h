#pragma once

#include <GL/glew.h>

class Renderable
{
private:
	GLuint _vao;
	GLuint _vbo;
	GLuint _ebo;
	GLuint _tex;
	int _elementCount;
public:
	Renderable(const GLsizeiptr bufferSize, const GLfloat *bufferData, const GLsizeiptr elementSize, const GLuint *elementData, const int elementCount, const char* texturePath);
	void setVertexData(const GLsizeiptr size, const GLfloat *data);
	void setElementData(const GLsizeiptr size, const GLuint *data);
	int getElementCount();
	int getVAO();
	int getTEX();
};
