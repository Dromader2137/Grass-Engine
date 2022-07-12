#pragma once

#include "../Material.h"

namespace grs
{
	namespace mat
	{
		class UnlitMaterial : public Material
		{
			public:
				Vector3f baseColor = Vector3f(1.0f, 1.0f, 1.0f);

				void ApplyParameters();
		};
	}
}