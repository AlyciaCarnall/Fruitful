#include "Entity.h"


void Entity::CheckCollision(Entity& other)
{
	//if booth entities are dead then this won't occur
	if (!IsAlive() || !other.IsAlive())
		return;

	if (!CanCollide(GetSide(), other.GetSide()))
		return;

	Rectangle myRect{ rect };

	int width{ myRect.width() };
	int height{ myRect.height() };

	myRect.left += width / 15;
	myRect.right -= width / 15;
	myRect.top += height / 15;
	myRect.bottom -= height / 15;

	Rectangle otherRect{ other.GetRect() };

	myRect.translate((int)mPos.x, (int)mPos.y);
	otherRect.translate((int)other.mPos.x, (int)other.mPos.y);

	if (!myRect.CompletelyOutside(otherRect))
	{
		TakeDamage(other.GetDamage());
		other.TakeDamage(GetDamage());
	}
}

bool Entity::CanCollide(const eSide& side, const eSide& other)
{
	if (side == eSide::ePlayer && other == eSide::eEnemy)
		return true;
	else if (side == eSide::eEnemy && other == eSide::ePlayer)
		return true;
	else
		return false;
}


void Entity::TakeDamage(const int& DamageReceived)
{
	mHealth - +DamageReceived;

	if (mHealth <= 0)
	{
		mAlive = false;
	}
}