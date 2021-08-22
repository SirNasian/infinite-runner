#include <list>
#include "../include/renderer.hpp"
#include "../include/renderable.hpp"
#include "../include/shader.hpp"

Renderer::Renderer()
{
};

void Renderer::Render(double time_delta)
{
	std::list<Renderable*>::iterator renderable;
	for (renderable = this->renderables.begin(); renderable != this->renderables.end(); renderable++)
		(*renderable)->Render();
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
