#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
	private:
		unsigned int program;
		unsigned int CompileShader(const char *source, GLenum shader_type);
	public:
		Shader(const char *vertexSource, const char *fragmentSource);
		~Shader();
		unsigned int GetProgram() { return this->program; };
		void UseProgram() { glUseProgram(this->program); };
		void SetMat4(const char *name, glm::mat4 value);
};

Shader* ConstructSimpleShader();
