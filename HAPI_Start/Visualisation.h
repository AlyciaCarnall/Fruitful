#pragma once

#include <HAPI_lib.h>
using namespace HAPISPACE;

#include <unordered_map>

class Sprite;

class Visualisation
{
private:

	int screenHeight{ 500 };
	int screenWidth{ 700 };
	int width{ 0 }, height{ 0 };

	BYTE* data{ nullptr };

	BYTE* screen{ nullptr };

	//to store our collection of sprites
	std::unordered_map<std::string, Sprite*> spriteMap;
public:

	Visualisation();
	~Visualisation();

	bool Initialise();

	//creates a sprite, it is bool because it might fail
	bool CreateSprite(const std::string& filename, const std::string& name);

	void ClearToBlack(BYTE black = 0);
	void BlitFastRender(const std::string& name, int screenPosX, int screenPosY) const;
	void BlitTransparentRender(const std::string& name, int screenPosX, int screenPosY) const;
	
	int getSpriteWidth(const std::string& name) const;
	int getSpriteHeight(const std::string& name) const;

	int getScreenWidth() const { return screenWidth; };
	int getScreenHeight() const { return screenHeight; };

};

