#pragma once
#include <algorithm>
#include <HAPI_lib.h>
using namespace HAPISPACE;

class Rectangle
{
public:
	int left{ 0 }, right{ 0 }, top{ 0 }, bottom{ 0 };
	BYTE* screen{ nullptr };
	BYTE* source{ nullptr };

	//constructor
	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}

	bool CompletelyOutside(const Rectangle& other)
	{
		if (other.right < left)
			return true;

		if (other.top > bottom)
			return true;

		if (other.left > right)
			return true;

		if (other.bottom < top)
			return true;

		return false;
	}

	bool CompletelyInside(const Rectangle& other)
	{
		if (left < other.left)
			return false;

		if (top < other.top)
			return false;

		if (right > other.right)
			return false;

		if (bottom > other.bottom)
			return false;

		return true;
	}

	void ClipTo(const Rectangle& other)
	{
		left = std::max(left, other.left);
		top = std::max(top, other.top);
		right = std::min(right, other.right);
		bottom = std::min(bottom, other.bottom);
	}

	int width() const { return right - left; };
	int height() const { return bottom - top; };

	void translate(int dX, int dY)
	{
		left += dX;
		right += dX;
		top += dY;
		bottom += dY;
	}
	
};

