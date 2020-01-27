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

	//get the screen pointer with an unsigned char with a pointer to the first byte of the screen
	screen = HAPI.GetScreenPointer();

	//get happy to show the framerate
	HAPI.SetShowFPS(true);

	return true;
}

bool Visualisation::CreateSprite(const std::string& filename, const std::string& name)
{
	//creates a sprite and loads itself
	Sprite* newSprite = new Sprite;
	if (!newSprite->Load(filename))
	{
		//stop memory leaks so we have to delete
		delete newSprite;
		return false;
	}

	//add the sprite to our container
	spriteMap[name] = newSprite;

	return true;
}

void Visualisation::ClearToBlack(BYTE black)
{	
	//fills the block of memory (the screen) with the desired colour 
	memset(screen, black, (size_t)screenWidth * screenHeight * 4);
}

void Visualisation::BlitFastRender(const std::string& name, int screenPosX, int screenPosY) const
{
	if (spriteMap.find(name) == spriteMap.end())
		return;

	spriteMap.at(name)->Render(screen, screenWidth, screenHeight, 960, 540, screenPosX, screenPosY);
}

//The named sprite will be blitted (allowed to be shown on and off the screen
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



