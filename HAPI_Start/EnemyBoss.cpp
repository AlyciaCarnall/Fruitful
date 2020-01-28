#include "EnemyBoss.h"


EnemyBoss::EnemyBoss(const std::string& name) : Entity(name)
{
	mSide = eSide::eEnemy;
	SetPosition(Vector2(400, 380));
}

EnemyBoss::~EnemyBoss()
{
}

void EnemyBoss::Update(const Visualisation& mVis)
{
	mVis.BlitTransparentRender(mGFXname, (int)mPos.x, (int)mPos.y);
	//AI

}
