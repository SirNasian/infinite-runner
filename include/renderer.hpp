#pragma once
#include <list>
#include "./renderable.hpp"

class Renderer
{
	private:
		std::list<Renderable*> renderables;
		unsigned int fps;
		float pos_x, pos_y, view_width, view_height;
	public:
		Renderer();
		void Render(double time_delta);
		void RegisterRenderable(Renderable *renderable);
		void UnregisterRenderable(Renderable *renderable);
		void UnregisterRenderables();
		void SetFPS(unsigned int fps) { this->fps = fps; };
		bool ShouldRender(float time_delta) { return (time_delta >= (1.0f / this->fps)); };
};
