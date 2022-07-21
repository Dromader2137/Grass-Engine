#pragma once

namespace grs
{
	class Vector3f
	{
		public:
			/* 3 dimensional coordinates */
			float x, y, z;

			Vector3f operator + (Vector3f a);
			Vector3f& operator += (Vector3f a);
			Vector3f operator - (Vector3f a);
			Vector3f& operator -= (Vector3f a);
			Vector3f operator * (float a);
			Vector3f& operator *= (float a);
			Vector3f operator / (float a);
			Vector3f& operator /= (float a);

			Vector3f Normalize();

			static float Dot(Vector3f a, Vector3f b);
			static Vector3f Cross(Vector3f a, Vector3f b);

			Vector3f(float x, float y, float z);
			Vector3f();
			~Vector3f();
	};
}