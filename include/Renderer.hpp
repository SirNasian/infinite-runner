#pragma once
#include <list>
#include "./Renderable.hpp"

class Renderer
{
	private:
		std::list<Renderable*> renderables;
		unsigned int fps;
		float pos_x, pos_y, view_width, view_height;
	public:
		Renderer();
		float GetViewWidth() { return this->view_width; };
		float GetViewHeight() { return this->view_height; };
		void SetFPS(unsigned int fps) { this->fps = fps; };
		void Render(double time_delta);
		void RegisterRenderable(Renderable *renderable);
		void UnregisterRenderable(Renderable *renderable);
		void UnregisterRenderables();
		bool ShouldRender(float time_delta) { return (time_delta >= (1.0f / this->fps)); };
};
