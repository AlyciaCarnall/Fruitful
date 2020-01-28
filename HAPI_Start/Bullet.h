#pragma once
#include "Entity.h"

class Bullet :	public Entity
{
private:
	Vector2 mDirection;

public:

	Bullet(const std::string& name);
	void Update(const Visualisation& mVis) override final;
};

