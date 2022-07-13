#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

namespace grs
{
	namespace mat
	{
		void Shader::CompileShader()
		{
			this->program = glCreateProgram();
			
			unsigned int vs = this->CompileTypeShader(&this->vertexSourceCode, GL_VERTEX_SHADER);
			unsigned int fs = this->CompileTypeShader(&this->fragmentSourceCode, GL_FRAGMENT_SHADER);

			glAttachShader(this->program, vs);
			glAttachShader(this->program, fs);
			glLinkProgram(this->program);
			glValidateProgram(this->program);

			#ifdef _DEBUG
			if (vs != 0 and fs != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << "\n-=- Shader compilation succesful! -=-\n\nName: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				std::cout << this->name;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << "\n\n-=- Vertex code -=-\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				std::cout << this->vertexSourceCode;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << "\n-=- Fragment code -=-\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				std::cout << this->fragmentSourceCode;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
				std::cerr << "\nCompilation of " << (shaderType == GL_VERTEX_SHADER ? "vertex" : "fragment") << " part in shader \"" << this->name << "\" failed!\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n" << *src << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
				std::cerr << "ERROR: " << message << "\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				#endif

				return 0;
			}

			return id;
		}

		Shader::Shader(std::string name, std::string vertexSourceCode, std::string fragmentSourceCode)
		{
			this->name = name;
			this->vertexSourceCode = vertexSourceCode;
			this->fragmentSourceCode; fragmentSourceCode;
		}

		Shader shaders[1];

		void InitShaders()
		{
			shaders[0].name = "Unlit";
			shaders[0].vertexSourceCode = "#version 440 core\n\nlayout (location = 0) in vec4 position;\n\nuniform mat4x4 u_MVP;\n\nvoid main()\n{\n\tgl_Position = position;\n}\n";
			shaders[0].fragmentSourceCode = "#version 440 core\n\nlayout (location = 0) out vec4 color;\n\nuniform vec4 u_baseColor;\n\nvoid main()\n{\n\tcolor = u_baseColor;\n}\n";
			shaders[0].CompileShader();
		}
	}
}