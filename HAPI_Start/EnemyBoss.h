#pragma once
#include "Entity.h"

class EnemyBoss : public Entity
{
public:

	EnemyBoss(const std::string& name);
	~EnemyBoss();

	void Update(const Visualisation& mVis) override final;

};

