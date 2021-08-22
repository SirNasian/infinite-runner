#include <GL/glew.h>
#include "../include/Shader.hpp"

Shader::Shader(const char *source_vertex, const char *source_fragment)
{
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

Shader::~Shader()
{
};

unsigned int Shader::CompileShader(const char *source, GLenum shader_type)
{
	unsigned int shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	// TODO: error handling
	return shader;
};

Shader ConstructSimpleShader()
{
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec2 aPos;\n"
		"uniform mat4 uModel;\n"
		"uniform mat4 uView;\n"
		"uniform mat4 uProjection;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = uProjection * uView * uModel * vec4(aPos, 0.0, 1.0);\n"
		"}\0";
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";
	return Shader(vertexShaderSource, fragmentShaderSource);
};
