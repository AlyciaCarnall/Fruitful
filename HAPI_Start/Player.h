#pragma once
#include "Entity.h"
#include <string>

class Player :	public Entity
{
public:
	Player(const std::string& name);

	void Update() override final;

	int getNumLives() const { return 0; }
};

