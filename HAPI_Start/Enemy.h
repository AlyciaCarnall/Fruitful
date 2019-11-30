#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:

	Enemy(std::string& name);
	~Enemy();

	void Update(const Visualisation& mVis) override final;

};

