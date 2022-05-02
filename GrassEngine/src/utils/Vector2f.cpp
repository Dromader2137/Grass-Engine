#include "Vector2f.h"

namespace grs
{
	Vector2f::Vector2f(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2f::Vector2f()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	Vector2f::~Vector2f() {}
} 