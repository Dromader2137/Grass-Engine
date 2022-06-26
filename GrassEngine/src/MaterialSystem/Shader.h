#pragma once

#include <string>

#include "../Types.h"

namespace grs
{
	namespace mat
	{
		class Shader
		{
			public:
				std::string vertexSourceCode;
				std::string fragmentSourceCode;
		};
	}
}