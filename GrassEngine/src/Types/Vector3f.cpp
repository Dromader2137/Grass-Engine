#include "Vector3f.h"

#include <math.h>

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
	Vector3f& Vector3f::operator*=(float a)
	{
		this->x *= a;
		this->y *= a;
		this->z *= a;
		return *this;
	}
	Vector3f Vector3f::operator/(float a)
	{
		return Vector3f(this->x / a, this->y / a, this->z / a);
	}
	Vector3f& Vector3f::operator/=(float a)
	{
		this->x /= a;
		this->y /= a;
		this->z /= a;
		return *this;
	}

	Vector3f Vector3f::Normalize()
	{
		return *this / sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	float Vector3f::Dot(Vector3f a, Vector3f b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	Vector3f Vector3f::Cross(Vector3f a, Vector3f b)
	{
		Vector3f vec;
		vec.x = a.y * b.z - a.z * b.y;
		vec.y = a.z * b.x - a.x * b.z;
		vec.z = a.x * b.y - a.y * b.x;
		return vec;
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