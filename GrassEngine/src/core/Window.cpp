#include <iostream>

#include "Window.h"

namespace grs
{
	void Window::RenderScene(Scene* scene)
	{
		std::cout << "Rendering a scene!";
	}

	Window::Window() {}
	Window::~Window() {}
}