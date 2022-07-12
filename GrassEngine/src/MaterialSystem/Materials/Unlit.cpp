#include "Unlit.h"

#include <GL/glew.h>

namespace grs
{
	namespace mat
	{
		void UnlitMaterial::ApplyParameters()
		{
			glUniform4f(glGetUniformLocation(this->shader.program, "u_baseColor"), this->baseColor.x, this->baseColor.y, this->baseColor.z, 1.0f);
		}
	}
}