#pragma once

#include <GL/glew.h>

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

				unsigned int shader;

				void CompileShader();

			private:
				static unsigned int CompileTypeShader(std::string* src, GLenum shaderType);
		};
	}
}