#pragma once
#include "Vector2.h"
#include "Visualisation.h"

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
	eSide mSide{ };
	int mHealth{ 0 };
	int mDamage{ 0 };
	std::string mGFXname;
	Vector2 mPos{ 0,0 };
	bool mAlive{ false };
	float mSpeed{ 0.2f };


public:

	Entity(const std::string& name);
	virtual ~Entity() = default;

	virtual void Update(const Visualisation & mVis) = 0;

	eSide GetSide() { return mSide; }
	
	//bool isEnemyOf(const Entity& other) const
	//{
	//	//if(getSide* )
	//}

	bool CheckCollision(const Entity& other) const;

};

