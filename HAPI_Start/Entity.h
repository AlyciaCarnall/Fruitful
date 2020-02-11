#pragma once
#include "Vector2.h"
#include "Visualisation.h"
#include "Rectangle.h"
#include "World.h"

#include <HAPI_lib.h>
using namespace HAPISPACE;

enum class eSide
{
	ePlayer,
	eEnemy,
	eNeutral
};

class Entity
{
protected:
	Vector2 mPos{ 0,0 };
	eSide mSide{ };
	int mHealth{ 10 };
	int mDamage{ 10 };
	std::string mGFXname;
	bool mAlive{ true };
	float mSpeed{ 0.2f };
	Rectangle rect;
	World world;
	bool isOnGround{ true };
public:

	Entity(const std::string& name) : mGFXname(name) {}
	virtual ~Entity() = default;

	virtual void Update(const Visualisation& mVis) = 0;

	eSide GetSide() { return mSide; }
	Rectangle GetRect() { return rect; }

	//because the position is private, the only time we can change it is to use this function
	void SetPosition(Vector2 newPos) { mPos = newPos; }

	int GetDamage() { return mDamage; }

	std::string GetName() { return mGFXname; }
	bool IsAlive() { return mAlive; }

	void CheckCollision(Entity& other);
	bool CanCollide(const eSide& side, const eSide& other);
	void TakeDamage(const int& DamageReceived);
};

