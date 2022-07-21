#pragma once

#include "Vector3f.h"

namespace grs
{
	class Quaternion
	{
		public:
			float x, y, z, w;

			Quaternion operator * (Quaternion a);
			Quaternion& operator *= (Quaternion a);
			Vector3f operator * (Vector3f a);

			Quaternion(float x, float y, float z, float w);
			Quaternion();
	};
}