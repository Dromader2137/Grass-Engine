#pragma once

#include <string>

#include "../Types.h";
#include "Shader.h";

namespace grs
{
	namespace mat
	{
		class Material
		{
			public:
				std::string name;

				Shader shader;

				void PrepareShader();

				/*
				void Set1Float(std::string memberName, float value);
				void Set2Float(std::string memberName, float value1, float value2);
				void Set3Float(std::string memberName, float value1, float value2, float value3);
				void Set4Float(std::string memberName, float value1, float value2, float value3, float value4);
				*/
		};
	}
}