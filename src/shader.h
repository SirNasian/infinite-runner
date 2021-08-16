#pragma once
#include <GL/glew.h>

class Shader {
	private:
		unsigned int program;
		unsigned int CompileShader(const char *source, GLenum shader_type);
	public:
		Shader(const char *vertexSource, const char *fragmentSource);
		~Shader();
};
