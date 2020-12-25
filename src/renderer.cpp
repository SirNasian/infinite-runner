#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "renderer.h"

Renderer::Renderer()
{
	this->_shaderProgram = this->createShaderProgram();
	this->_viewUniform = glGetUniformLocation(this->_shaderProgram, "view");
	this->_projectionUniform = glGetUniformLocation(this->_shaderProgram, "projection");
}

void Renderer::render(Renderable *renderable)
{
	glUseProgram(this->_shaderProgram);

	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(this->_viewUniform, 1, GL_FALSE, glm::value_ptr(view));

	// TODO: set projection to match current window and viewport
	glm::mat4 projection = glm::ortho(0.0f, 400.0f, 0.0f, 400.0f, 0.0f, 2.0f);
	glUniformMatrix4fv(this->_projectionUniform, 1, GL_FALSE, glm::value_ptr(projection));

	glBindVertexArray(renderable->getVAO());
	glDrawElements(GL_TRIANGLES, renderable->getElementCount(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

GLuint Renderer::createShaderProgram()
{
	const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec2 aPos;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main() {\n"
		"  gl_Position = projection * view * vec4(aPos, 0.0f, 1.0f);\n"
		"}\0";
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	const GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColour;\n"
		"void main() {FragColour = vec4(1.0f, 0.0f, 0.0f, 1.0f);}\0";
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	const GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}
