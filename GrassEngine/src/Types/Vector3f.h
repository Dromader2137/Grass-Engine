#pragma once

namespace grs
{
	class Vector3f
	{
		public:
			/* 2 dimensional coordinates */
			float x, y, z;

			Vector3f(float x, float y, float z);
			Vector3f();
			~Vector3f();
	};
}