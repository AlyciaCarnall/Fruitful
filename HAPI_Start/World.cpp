#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
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

bool World::Initialise()
{
	if (!mVis->CreateSprite("data\\orange.png", "Player"))
		HAPI.UserMessage("Unable to load player", "ERROR");

	if(!mVis->CreateSprite("data\\science-fiction-1597341_960_720.png", "Background"))
		HAPI.UserMessage("Unable to load background", "ERROR");

	Player *newPlayer = new Player("Player");

	entityVector.push_back(newPlayer);

	for (int i{ 0 }; i < 200; ++i)
	{
		Bullet* newBullet = new Bullet("Bullet");
		entityVector.push_back(newBullet);
	}

	return true;
}

void World::Run()

{	mVis = new Visualisation;

	if (!mVis->Initialise())
		HAPI.UserMessage("Unable to initialise", "ERROR");

	if(!Initialise())
		HAPI.UserMessage("Unable to initialise", "ERROR");


	while (HAPI.Update())
	{

		mVis->ClearToBlack(0);		
		mVis->BlitFastRender("Background", 0, 0);
		mVis->BlitTransparentRender("Player", 0, 0);


		/*for (auto& p : entityVector)
			p->Update();*/

		for (size_t i{ 0 }; i < entityVector.size(); ++i)
		{
			for (size_t j{ i+1 }; j < entityVector.size(); ++j)
			{
				//if(entityVector[i]->isEnemyOf(*entityVector[j]))

				//entityVector[i]->CheckCollision(*entityVector[j]);

				entityVector[i]->Update();
			}
		}
	}
}
