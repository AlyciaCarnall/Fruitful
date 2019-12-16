#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	Vector2 newPos{ 540,960 };
public:
	
	Player(const std::string& name);
	~Player();

	void Update(const Visualisation& mVis) override final;

	int getNumLives() const { return 0; }
	
};

