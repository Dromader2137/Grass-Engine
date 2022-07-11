#include "Material.h"

namespace grs
{
	namespace mat
	{
		void Material::PrepareShader()
		{
			shader.CompileShader();
		}
	}
}