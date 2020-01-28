#include "World.h"

void HAPI_Main()
{
	World* world = new World;

	world->Initialise();
	world->Run();
	
	return;
}