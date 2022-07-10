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
				std::string name;

				std::string vertexSourceCode;
				std::string fragmentSourceCode;
		};
	}
}