#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <list>
#include "../include/Renderer.hpp"
#include "../include/Renderable.hpp"
#include "../include/Shader.hpp"

Renderer::Renderer()
{
	this->fps         =  60;
	this->pos_x       =   0;
	this->pos_y       =   0;
	this->view_width  = 640;
	this->view_height = 480;
};

void Renderer::Render(double time_delta)
{
	glm::mat4 mat_view = glm::translate(glm::mat4(1.0f), glm::vec3(-this->pos_x, -this->pos_y, 0.0f));
	glm::mat4 mat_projection = glm::ortho(0.0f, this->view_width, this->view_height, 0.0f, 0.0f, 1.0f);
	std::list<Renderable*>::iterator renderable;
	for (renderable = this->renderables.begin(); renderable != this->renderables.end(); renderable++)
		(*renderable)->Render(mat_view, mat_projection);
};

void Renderer::RegisterRenderable(Renderable *renderable)
{
	this->renderables.push_back(renderable);
	this->renderables.unique();
};

void Renderer::UnregisterRenderable(Renderable *renderable)
{
	this->renderables.remove(renderable);
};

void Renderer::UnregisterRenderables()
{
	this->renderables.clear();
};
