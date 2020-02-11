#pragma once

#include <HAPI_lib.h>
using namespace HAPISPACE;

class Visualisation;
class Entity;

enum class GameMode
{
	menu_State,
	in_Game_State,
	end_Game_State,
	restart_Game_State,
	quit_state
};

class World
{
protected:
	//Visualisation instance
	Visualisation *mVis{ nullptr };
	
	std::vector<Entity*> entityVector;

	GameMode mode{ GameMode::menu_State };

	
public:
	
	World() { }
	~World();

	void Update();

	bool Initialise();
	bool Load();

	void Run();

	void MainMenu();

	void Play();

	void EndGame();

	GameMode GetState() { return mode; }
	void SetState(const GameMode& newstate) { mode = newstate; }

	//void FireBullet(eSide side);
};

