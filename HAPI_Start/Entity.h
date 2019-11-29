#pragma once
#include "Vector2.h"

#include <HAPI_lib.h>
using namespace HAPISPACE;

enum class eSide
{
	ePlayer,
	eEnemy,
	eNeutral
};

class Visualisation;

class Entity
{
protected:
	eSide mSide{ };
	int mHealth{ 0 };
	int mDamage{ 0 };
	std::string mGFXname;
	Vector2 mPos;	
	bool mAlive{ false };
	float mSpeed{ 5.0f };

public:

	Entity(const std::string& name);
	virtual ~Entity() = default;

	void SetPosition(Vector2 newPos) { mPos = newPos; }

	virtual void Update() = 0;

	eSide GetSide() { return mSide; }
	
	//bool isEnemyOf(const Entity& other) const
	//{
	//	//if(getSide* )
	//}

	bool CheckCollision(const Entity& other) const;

};

