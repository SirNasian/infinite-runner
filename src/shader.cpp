#include <GL/glew.h>
#include "shader.h"

Shader::Shader(const char *source_vertex, const char *source_fragment) {
	unsigned int shader_vertex   = this->CompileShader(source_vertex, GL_VERTEX_SHADER);
	unsigned int shader_fragment = this->CompileShader(source_fragment, GL_FRAGMENT_SHADER);
	this->program = glCreateProgram();
	glAttachShader(this->program, shader_vertex);
	glAttachShader(this->program, shader_fragment);
	glLinkProgram(this->program);
	// TODO: error handling
	glDeleteShader(shader_vertex);
	glDeleteShader(shader_fragment);
};

Shader::~Shader() {
};

unsigned int Shader::CompileShader(const char *source, GLenum shader_type) {
	unsigned int shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	// TODO: error handling
	return shader;
};
