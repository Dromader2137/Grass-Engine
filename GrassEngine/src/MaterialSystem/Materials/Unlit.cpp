#include "Unlit.h"

#include <GL/glew.h>

namespace grs
{
	namespace mat
	{
		void UnlitMaterial::ApplyParameters()
		{
			glUniform4f(glGetUniformLocation(this->shader->program, "u_baseColor"), this->baseColor.x, this->baseColor.y, this->baseColor.z, 1.0f);
		}

		void UnlitMaterial::PrepareShader()
		{
			this->shader = &shaders[ShaderType::Unlit];
		}

		UnlitMaterial::UnlitMaterial(Vector3f color)
		{
			this->baseColor = color;
		}
	}
}