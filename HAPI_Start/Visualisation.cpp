#include "Visualisation.h"
#include "Sprite.h"

Visualisation::Visualisation()
{
}

Visualisation::~Visualisation()
{
	delete[]data;
}

bool Visualisation::Initialise()
{
	//Functions should be called after HAPI is initialized
	if (!HAPI.Initialise(screenWidth, screenHeight, "Fruitful Alycia Carnall T7022349"))
		return false;

	screen = HAPI.GetScreenPointer();

	HAPI.SetShowFPS(true);

	return true;
}

bool Visualisation::CreateSprite(const std::string& filename, const std::string& name)
{

	Sprite* newSprite = new Sprite;
	if (!newSprite->Load(filename))
	{
		delete newSprite;
		return false;
	}

	spriteMap[name] = newSprite;

	return true;
}

void Visualisation::ClearToBlack(BYTE black)
{

	memset(screen, black, (size_t)screenWidth * screenHeight * 4);
}

void Visualisation::BlitFastRender(const std::string& name, int screenPosX, int screenPosY) const
{
	if (spriteMap.find(name) == spriteMap.end())
		return;

	spriteMap.at(name)->Render(screen, screenWidth, screenHeight, 960, 540, screenPosX, screenPosY);
}

void Visualisation::BlitTransparentRender(const std::string& name, int screenPosX, int screenPosY) const
{
	if (spriteMap.find(name) == spriteMap.end())
		return;

	spriteMap.at(name)->BlitRender(screen, screenWidth, screenHeight, screenPosX, screenPosY);
}

int Visualisation::getSpriteWidth(const std::string& name) const
{
	return spriteMap.at(name)->getTextureWidth();
}

int Visualisation::getSpriteHeight(const std::string& name) const 
{
	return spriteMap.at(name)->getTextureHeight();
}



