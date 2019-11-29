#pragma once

#include <HAPI_lib.h>
using namespace HAPISPACE;

#include <unordered_map>

class Sprite;

class Visualisation
{
private:

	int screenHeight{ 540 };
	int screenWidth{ 960 };
	int width{ 0 }, height{ 0 };

	BYTE* data{ nullptr };

	BYTE* screen{ nullptr };

	std::unordered_map<std::string, Sprite*> spriteMap;
public:

	Visualisation();
	~Visualisation();

	bool Initialise();

	bool CreateSprite(const std::string& filename, const std::string& name);

	void ClearToBlack(BYTE black = 0);
	void BlitFastRender(const std::string& name, int screenPosX, int screenPosY);
	void BlitTransparentRender(const std::string& name, int screenPosX, int screenPosY) const;
	
	int getSpriteWidth(const std::string& name);
	int getSpriteHeight(const std::string& name);

	int getScreenWidth() { return screenWidth; };
	int getScreenHeight() { return screenHeight; };

};

