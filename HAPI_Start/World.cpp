#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Background.h"
#include "EnemyBoss.h"
#include "Bullet.h"


World::World()
{

}

World::~World()
{
	delete mVis;

	for (auto p : entityVector)
		delete p;
}

bool World::Load()
{
	if (!mVis->CreateSprite("data\\orange.png", "Player"))
		HAPI.UserMessage("Unable to load player", "ERROR");

	if(!mVis->CreateSprite("data\\science-fiction-1597341_960_720.png", "Background"))
		HAPI.UserMessage("Unable to load background", "ERROR");

	if (!mVis->CreateSprite("data\\burger.png", "EnemyBoss"))
		HAPI.UserMessage("Unable to load Enemy Boss", "ERROR");

	Background *newBackgorund = new Background("Background");
	Player *newPlayer = new Player("Player");
	EnemyBoss* newBossEnemy = new EnemyBoss("EnemyBoss");


	entityVector.push_back(newBackgorund);

	entityVector.push_back(newBossEnemy);
	entityVector.push_back(newPlayer);

	/*for (int i{ 0 }; i < 200; ++i)
	{
		Bullet* newBullet = new Bullet("Bullet");
		entityVector.push_back(newBullet);
	}*/

	return true;
}

void World::Run()

{	mVis = new Visualisation;

	if (!mVis->Initialise())
		HAPI.UserMessage("Unable to initialise", "ERROR");

	if(!Load())
		HAPI.UserMessage("Unable to load", "ERROR");

		
	while (HAPI.Update())
	{
		mVis->ClearToBlack(0);		

		for (auto& p : entityVector)
			p->Update(*mVis);

		for (size_t i{ 0 }; i < entityVector.size(); ++i)
		{
			for (size_t j{ i+1 }; j < entityVector.size(); ++j)
			{
				//if(entityVector[i]->isEnemyOf(*entityVector[j]))

				//entityVector[i]->CheckCollision(*entityVector[j]);

			}
		}
	}
}
