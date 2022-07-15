#pragma once

#include <GL/glew.h>

#include <string>

#include "Types.h"

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

				unsigned int program = 0;

				void CompileShader();

				Shader(std::string name, std::string vertexSourceCode, std::string fragmentSourceCode);
				Shader() {}

			private:
				unsigned int CompileTypeShader(std::string* src, GLenum shaderType);
		};

		extern Shader shaders[1];
		void InitShaders();
	}
}