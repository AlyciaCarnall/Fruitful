#include "Entity.h"



Entity::Entity(const std::string& name) : mGFXname(name)
{


}

bool Entity::CheckCollision(const Entity& other) const
{
	return false;
}
