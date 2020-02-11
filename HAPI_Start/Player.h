#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const std::string& name);
	~Player() {}

	void Update(const Visualisation& mVis) override final;
};

