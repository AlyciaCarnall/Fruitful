#pragma once
#include <cmath>

class Vector2
{
public:

	float x{ 0 };
	float y{ 0 };

	Vector2() = default;
	Vector2(float newX, float newY) : x(newX), y(newY) {}

	//+ operator
	Vector2 operator + (const Vector2& rhs) const
	{
		return Vector2(x + rhs.x, y + rhs.y);
	}

	//- operator
	Vector2 operator - (const Vector2& rhs) const
	{
		return Vector2(x - rhs.x, y - rhs.y);
	}
		
	//* operator
	Vector2 operator * (float rhs) const
	{
		return Vector2(x * rhs, y * rhs);
	}

	//*= operator
	Vector2& operator *= (float rhs)
	{
		return Vector2(x *= rhs, y *= rhs);
	}

	//squared length to stop the sqrt from being too slow
	float SquaredLength( float x, float y)
	{
		x = x * x;
		y = y * y;

		float z = x + y;
		return z;
	}

	//returns magintude 
	float Length()
	{
		
		return sqrt(SquaredLength(x,y));
	}

	//normalise so its length is 1
	void NormaliseInPlace()
	{
		float len = Length();

		if (len == 0)
			return;

		x /= len;
		y /= len;
	}

	//dot product to calculate angle
	float Dot(const Vector2& other) const
	{
		return x * other.x + y * other.y;
	}

	//cross product
	float Cross(const Vector2& other) const
	{
		return x * other.x - y * other.y;
	}
};

