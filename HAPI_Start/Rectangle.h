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

	//default constructor
	Rectangle() {}

	//constructor
	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}

	bool CompletelyOutside(const Rectangle& other);
	

	bool CompletelyInside(const Rectangle& other);
	

	void ClipTo(const Rectangle& other);

	int width() const { return right - left; };
	int height() const { return bottom - top; };

	void translate(int dX, int dY);

	
};

