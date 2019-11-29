#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:

	Enemy(std::string& name);
	~Enemy();

	void Update() override final;

};

