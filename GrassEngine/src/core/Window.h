#pragma once

#include "Scene.h"

namespace grs
{
	class Window
	{
		public:
			void RenderScene(Scene *scene);

			Window();
			~Window();
	};
}