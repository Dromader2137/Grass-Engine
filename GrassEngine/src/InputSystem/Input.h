#pragma once

#include "Core.h"

namespace grs
{
	class Input
	{
		public:
			static bool IsKeyDown(int keyCode);
			
			static bool IsKeyPressed(int keyCode);
			static bool IsButtonPressed(int keyCode);
	};
}