#include "Vector3f.h"

namespace grs
{
	Vector3f Vector3f::operator+(Vector3f a)
	{
		return Vector3f(this->x + a.x, this->y + a.y, this->z + a.z);
	}
	Vector3f& Vector3f::operator+=(Vector3f a)
	{
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
		return *this;
	}
	Vector3f Vector3f::operator-(Vector3f a)
	{
		return Vector3f(this->x - a.x, this->y - a.y, this->z - a.z);
	}
	Vector3f& Vector3f::operator-=(Vector3f a)
	{
		this->x -= a.x;
		this->y -= a.y;
		this->z -= a.z;
		return *this;
	}
	Vector3f Vector3f::operator*(float a)
	{
		return Vector3f(this->x * a, this->y * a, this->z * a);
	}
	Vector3f Vector3f::operator/(float a)
	{
		return Vector3f(this->x / a, this->y / a, this->z / a);
	}

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