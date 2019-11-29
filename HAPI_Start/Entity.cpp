#include "Entity.h"
#include "Visualisation.h"

Entity::Entity(const std::string& name) : mGFXname(name)
{
}

void Entity::Render(Visualisation& mVis)
{
	mVis.BlitTransparentRender(mGFXname, (int)mPos.x, (int)mPos.y);
}

bool Entity::CheckCollision(const Entity& other) const
{
	return false;
}
