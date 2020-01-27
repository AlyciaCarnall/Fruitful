#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;

class Sprite
{
private:
	int textureWidth{ 0 }, textureHeight{ 0 };
	BYTE* data{ nullptr };
	
public:
	Sprite();
	~Sprite();

	bool Load(const std::string& filename);

	void Render(BYTE* screen, int screenWidth, int screenHeight, int texWidth, int texHeight, int posX, int posY);
	void BlitRender(BYTE* screen, int screenWidth, int screenHeight, int posX, int poY);


	int getTextureWidth() { return textureWidth; };
	int getTextureHeight() { return textureHeight; };
};

