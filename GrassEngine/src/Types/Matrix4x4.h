#pragma once

#include "Vector3f.h"
#include "Quaternion.h"

#include <iostream>

namespace grs
{
	class Matrix4x4
	{
		public:
			float content[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

			Matrix4x4 operator + (Matrix4x4 a);
			Matrix4x4& operator += (Matrix4x4 a);
			Matrix4x4 operator - (Matrix4x4 a);
			Matrix4x4& operator -= (Matrix4x4 a);
			Matrix4x4 operator * (Matrix4x4 a);
			Matrix4x4& operator *= (Matrix4x4 a);

			static Matrix4x4 CreateScaleMatrix(Vector3f scale);
			static Matrix4x4 CreateTranslateMatrix(Vector3f translation);
			static Matrix4x4 CreateRotateMatrix(Quaternion rotation);
			static Matrix4x4 CreatePerspectiveMatrix(float FOV, float XYRatio, float nearCP, float farCP);
			static Matrix4x4 CreateLookAtMatrix(Vector3f eye, Vector3f center, Vector3f up);

			friend std::ostream& operator << (std::ostream& os, const Matrix4x4& mat);
	};
}