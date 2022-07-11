#include "Shader.h"

#include <iostream>

namespace grs
{
	namespace mat
	{
		void Shader::CompileShader()
		{
			this->shader = glCreateProgram();

			unsigned int vs = CompileTypeShader(&this->vertexSourceCode, GL_VERTEX_SHADER);
			unsigned int fs = CompileTypeShader(&this->fragmentSourceCode, GL_FRAGMENT_SHADER);

			glAttachShader(this->shader, vs);
			glAttachShader(this->shader, fs);
			glLinkProgram(this->shader);
			glValidateProgram(this->shader);

			glDeleteShader(vs);
			glDeleteShader(fs);
		}

		unsigned int Shader::CompileTypeShader(std::string* src, GLenum shaderType)
		{
			unsigned int id = glCreateShader(shaderType);
			const char* c_src = src->c_str();
			glShaderSource(id, 1, &c_src, nullptr);
			glCompileShader(id);

			int result;
			glGetShaderiv(id, GL_COMPILE_STATUS, &result);
			if (!result)
			{
				int length;
				glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
				char* message = (char*)alloca(length * sizeof(char));
				glGetShaderInfoLog(id, length, &length, message);

				std::cerr << "Compilation of " << (shaderType == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader failed!\n";
				std::cerr << "ERROR: " << message << "\n";
			}

			return id;
		}
	}
}