#include "EnemyBoss.h"


EnemyBoss::EnemyBoss(const std::string& name) : Entity(name)
{
}

EnemyBoss::~EnemyBoss()
{
}

void EnemyBoss::Update(const Visualisation& mVis)
{
	mVis.BlitTransparentRender(mGFXname, (int)mPos.x, (int)mPos.y);
	//AI

}
