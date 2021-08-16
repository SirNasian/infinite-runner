#pragma once
#include <list>
#include "renderable.h"

class Renderer
{
	private:
		std::list<Renderable*> renderables;
	public:
		Renderer();
		void Render(double time_delta);
		void RegisterRenderable(Renderable *renderable);
		void UnregisterRenderable(Renderable *renderable);
		void UnregisterRenderables();
};
