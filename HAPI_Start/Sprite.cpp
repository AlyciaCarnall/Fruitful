#include "Sprite.h"
#include "Rectangle.h"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
	// to avoid memory leaks
	delete[]m_data;
}

bool Sprite::Load(const std::string & filename)
{
	if (!HAPI.LoadTexture(filename, &m_data, textureWidth, textureHeight))
		return false;

	return true;
}

//fast render that simply displays the named sprite on screen with no transparency and blit capabilities 
void Sprite::Render(BYTE* screen, int screenWidth, int screenHeight, int texWidth, int texHeight, int posX, int posY)
{
	BYTE* screenPointer = screen + ((size_t)posX + (size_t)posY * screenWidth) * 4;
	BYTE* texturePointer = m_data;

	for (int y = 0; y < texHeight; y++)
	{
		memcpy(screenPointer, texturePointer, (size_t)texWidth * 4);

		// Move texture pointer to next line
		texturePointer += (size_t)texWidth * 4;

		// Move screen pointer to next line
		screenPointer += (size_t)screenWidth * 4;
	}

}

//The named sprite is able to be drawn on and off the screen
void Sprite::BlitRender(BYTE* screen, int screenWidth, int screenHeight, int posX, int posY)
{
	//Two rectangles, with destRect being the top left of the screen,
	// and the sourceRect is the top left of the texture
	Rectangle destRect(0, screenWidth, 0, screenHeight);
	Rectangle sourceRect(0, textureWidth, 0, textureHeight);

	//transform the source rectangle into destination space
	sourceRect.translate(posX, posY);

	//clip against the destination rect
	sourceRect.ClipTo(destRect);

	//transform back to source space
	sourceRect.translate(-posX, -posY);

	//clamp negative position values to 0;
	if (posX < 0)
		posX = 0;
	if (posY < 0)
		posY = 0;

	BYTE* screenPointer = screen + ((size_t)posX + (size_t)posY * screenWidth) * 4;
	BYTE* texturePointer = m_data + (sourceRect.left + (size_t)sourceRect.top * textureWidth) * 4;

	const int height = sourceRect.height();
	const int width = sourceRect.width();

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			BYTE red = texturePointer[0];
			BYTE green = texturePointer[1];
			BYTE blue = texturePointer[2];
			BYTE alpha = texturePointer[3];

			//if the alpha is greater than nothing will happen but if alpha is 255 then it will output to the screen
			if (alpha > 0)
			{
				if (alpha == 255)
				{
					memcpy(screenPointer, texturePointer, 4);
				}
				else
				{
					screenPointer[0] = screenPointer[0] + ((alpha * (blue - screenPointer[0])) >> 8);
					screenPointer[1] = screenPointer[1] + ((alpha * (green - screenPointer[1])) >> 8);
					screenPointer[2] = screenPointer[2] + ((alpha * (red - screenPointer[2])) >> 8);
				}
			}
			texturePointer += 4;
			screenPointer += 4;
		}
		screenPointer += ((size_t)screenWidth - sourceRect.width()) * 4;
		texturePointer += ((size_t)textureWidth - sourceRect.width()) * 4;
	}
}