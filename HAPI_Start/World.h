#pragma once

#include <HAPI_lib.h>
using namespace HAPISPACE;

class Visualisation;
class Entity;

class World
{
private:

	Visualisation *mVis{ nullptr };

	
	std::vector<Entity*> entityVector;

public:

	World();
	~World();

	bool Initialise();
	void Run();

	//void FireBullet(eSide side);
};

