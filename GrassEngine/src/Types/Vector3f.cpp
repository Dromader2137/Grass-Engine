#include "Vector3f.h"

namespace grs
{
	/* Constructors etc. */
	Vector3f::Vector3f(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3f::Vector3f()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}
	Vector3f::~Vector3f() {}
} 