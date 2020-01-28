#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Background.h"
#include "EnemyBoss.h"
#include "Bullet.h"

World::~World()
{
	//dynamic memory needs to be deleted after being used
	delete mVis;

	for (auto p : entityVector)
		delete p;
}

void World::Update()
{
	switch (mode)
	{
	case GameMode::menu_State:
		MainMenu();
		break;

	case GameMode::in_Game_State:
		Play();
		break;

	case GameMode::end_Game_State:
		break;

	case GameMode::restart_Game_State:
		break;

	default:
		break;
	}

}

bool World::Initialise()
{
	mVis = new Visualisation;

	if (!mVis->Initialise())
		HAPI.UserMessage("Unable to initialise", "ERROR");

	if (!Load())
		HAPI.UserMessage("Unable to load", "ERROR");

	return true;
}

bool World::Load()
{
	//Creates sprites using visualisation 
	if (!mVis->CreateSprite("data\\orange.png", "Player"))
		HAPI.UserMessage("Unable to load player", "ERROR");

	Player *newPlayer = new Player("Player");		

	if (!mVis->CreateSprite("data\\kitchen.png", "Background"))
		HAPI.UserMessage("Unable to load background", "ERROR");

	Background* newBackground = new Background("Background");
	
	if (!mVis->CreateSprite("data\\burger.png", "EnemyBoss"))
		HAPI.UserMessage("Unable to load Enemy Boss", "ERROR");
	
	EnemyBoss *newBossEnemy = new EnemyBoss("EnemyBoss");

	entityVector.push_back(newBackground);
	entityVector.push_back(newBossEnemy);
	entityVector.push_back(newPlayer);

	newPlayer->SetPosition(Vector2(0,380));
	newBossEnemy->SetPosition(Vector2(400, 270));

	/*for (int i{ 0 }; i < 200; ++i)
	{
		Bullet* newBullet = new Bullet("Bullet");
		entityVector.push_back(newBullet);
	}*/

	return true;
}

void World::Run()
{
	while (HAPI.Update())
		Update();
}

void World::MainMenu()
{
	mVis->ClearToBlack(0);
	
	while ((HAPI.Update()) && (mode == GameMode::menu_State))
	{	
		const HAPI_TKeyboardData& Key = HAPI.GetKeyboardData();
		const HAPI_TControllerData& Controller = HAPI.GetControllerData(0);
		
		if ((Key.scanCode['A']))
			mode = GameMode::in_Game_State;
		else if ((Key.scanCode['B']))
			HAPI.Close();
		
		if (Controller.isAttached)
		{
			if (Controller.digitalButtons[HK_DIGITAL_A])
				mode = GameMode::in_Game_State;
			else if (Controller.digitalButtons[HK_DIGITAL_B])
				HAPI.Close();
		}
	}
}

void World::Play()
{	
	mVis->ClearToBlack(0);	
	while ((HAPI.Update()) &&(mode == GameMode::in_Game_State))
	{
		for (auto& p : entityVector)
			p->Update(*mVis);

		for (size_t i{ 0 }; i < entityVector.size(); ++i)
		{
			for (size_t j{ i+1 }; j < entityVector.size(); ++j)
			{
				//if(entityVector[i]->isEnemyOf(*entityVector[j]);
				//entityVector[i]->CheckCollision(*entityVector[j]);

			}
		}
	}
}
