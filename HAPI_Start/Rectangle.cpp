#include "Rectangle.h"

bool Rectangle::CompletelyOutside(const Rectangle& other)
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

bool Rectangle::CompletelyInside(const Rectangle& other)
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

void Rectangle::ClipTo(const Rectangle& other)
{
	left = std::max(left, other.left);
	top = std::max(top, other.top);
	right = std::min(right, other.right);
	bottom = std::min(bottom, other.bottom);
}

void Rectangle::translate(int dX, int dY)
{
	left += dX;
	right += dX;
	top += dY;
	bottom += dY;
}