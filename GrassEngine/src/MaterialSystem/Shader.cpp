#include "Shader.h"

#include <iostream>
#include <windows.h>

namespace grs
{
	namespace mat
	{
		void Shader::CompileShader()
		{
			this->shader = glCreateProgram();
			
			unsigned int vs = this->CompileTypeShader(&this->vertexSourceCode, GL_VERTEX_SHADER);
			unsigned int fs = this->CompileTypeShader(&this->fragmentSourceCode, GL_FRAGMENT_SHADER);

			glAttachShader(this->shader, vs);
			glAttachShader(this->shader, fs);
			glLinkProgram(this->shader);
			glValidateProgram(this->shader);

			#ifdef _DEBUG
			if (vs != 0 and fs != 0)
			{
				std::cout << "\n--- Shader compilation succesful! ---\n\nName: " << this->name <<
					"\n\n--- Vertex code ---\n\n" << this->vertexSourceCode <<
					"\n--- Fragment code ---\n\n" << this->fragmentSourceCode <<
					"\n------------------------------------\n";
			}
			#endif

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

				#ifdef _DEBUG
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cerr << "\nCompilation of " << (shaderType == GL_VERTEX_SHADER ? "vertex" : "fragment") << " part in shader \"" << this->name << "\" failed!\n";
				std::cerr << "ERROR: " << message << "\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				#endif

				return 0;
			}

			return id;
		}
	}
}