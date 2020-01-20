#pragma once

#include <HAPI_lib.h>
using namespace HAPISPACE;

class Visualisation;
class Entity;

class World
{
private:
	//Visualisation instance
	Visualisation *mVis{ nullptr };
	
	std::vector<Entity*> entityVector;

public:
	
	World() {}
	~World();

	bool Load();
	void Run();

	//void FireBullet(eSide side);
};

