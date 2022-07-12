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

		void UnlitMaterial::PrepareShader()
		{
			this->shader = Shader();

			this->shader.vertexSourceCode = "#version 440 core\n\nlayout (location = 0) in vec4 position;\n\nvoid main()\n{\n\tgl_Position = position;\n}\n";
			this->shader.fragmentSourceCode = "#version 440 core\n\nlayout (location = 0) out vec4 color;\n\nuniform vec4 u_baseColor;\n\nvoid main()\n{\n\tcolor = u_baseColor;\n}\n";
			this->shader.name = "Unlit";

			this->shader.CompileShader();
		}
	}
}