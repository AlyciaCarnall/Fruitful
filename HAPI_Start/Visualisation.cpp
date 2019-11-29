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

void Visualisation::BlitFastRender(const std::string& name, int posX, int posY)
{
	BYTE* screenPointer = screen + ((size_t)posX + (size_t)posY * screenWidth) * 4;
	BYTE* texturePointer = data;

	for (int y = 0; y < height; y++)
	{
		memcpy(screenPointer, texturePointer, (size_t)width * 4);

		// Move texture pointer to next line
		texturePointer += (size_t)width * 4;

		// Move screen pointer to next line
		screenPointer += (size_t)screenWidth * 4;
	}

}

void Visualisation::BlitTransparentRender(const std::string& name, int screenPosX, int screenPosY) const
{
	if (spriteMap.find(name) == spriteMap.end())
		return;

	spriteMap.at(name)->Render(screen, screenWidth, screenHeight, screenPosX, screenPosY);
}

int Visualisation::getSpriteWidth(const std::string& name)
{
	return spriteMap[name]->getTextureWidth();
}

int Visualisation::getSpriteHeight(const std::string& name)
{
	return spriteMap[name]->getTextureHeight();
}



