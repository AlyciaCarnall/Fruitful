#include "Entity.h"

bool Entity::CheckCollision(Entity& other)
{
	//if booth entities are dead then this won't occur
	if (!isAlive() || !other.isAlive())
		return;

	Rectangle myRect{ rect };

	//gets the width and height
	int width{ myRect.width() };
	int height{ myRect.height() };

	//myRect.left = std::max(left, other.left);
	//myRect.top = std::max(top, other.top);
	//myRect.right = std::min(right, other.right);
	//myRect.bottom = std::min(bottom, other.bottom);

	return false;
}
