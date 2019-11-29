/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file
	
	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI:
	https://scm-intranet.tees.ac.uk/users/u0018197/hapi.html
*/

#include "Visualisation.h"
#include "Sprite.h"

// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down
void HAPI_Main()
{

	Visualisation visualise;

	if (!visualise.initialise())
		return;
	
	if (!visualise.CreateSprite("data\\playerSprite.tga", "player"))
		return;

	if (!visualise.CreateSprite("data\\science-fiction-1597341_960_720.png", "background"))
		return;

	HAPI.SetShowFPS(true);

	int posX{ 0 }, posY{ 0 };

	while (HAPI.Update())
	{
		visualise.ClearToBlack(0);
		visualise.BlitTransparentRender("background", 0 ,0);
		visualise.BlitTransparentRender("player", posX, posY);


		//Moving the player sprite using keyboard input.
		const HAPI_TKeyboardData& Key = HAPI.GetKeyboardData();

		//move around
		if ((Key.scanCode[HK_RIGHT]))
			posX += 5;

		if ((Key.scanCode[HK_LEFT])) 
			posX -= 5;

		if ((Key.scanCode[HK_DOWN])) 
			posY += 5;

		if ((Key.scanCode[HK_UP]))
			posY -= 5;
	
		//if the player is in the middle of the screen then if a controller is attatched it will rumble
		int controller{ 0 };
		const HAPI_TControllerData& Controller = HAPI.GetControllerData(controller);

		if (Controller.isAttached)
		{
			if (Controller.digitalButtons[HK_DIGITAL_DPAD_RIGHT])
			{
				posX += 5;
			}
			if (Controller.digitalButtons[HK_DIGITAL_DPAD_LEFT])
			{
				posX -= 5;
			}
			if (Controller.digitalButtons[HK_DIGITAL_DPAD_DOWN])
			{
				posY += 5;
			}
			if (Controller.digitalButtons[HK_DIGITAL_DPAD_UP])
			{
				posY -= 5;
			}

			//if (posX == (visualise.getScreenWidth() / 2) && posY == (visualise.getScreenHeight() / 2))
			//540 height /2 270
			//960 width / 2 480

			//720   360  posy
			//1280  640  pos 

			if ((posX >= 475 && posX <= 485) && (posY >= 255 && posY <= 285))
			{
				HAPI.SetControllerRumble(controller, 65535, 65535);

			}
			else
				HAPI.SetControllerRumble(controller, 0, 0);

		}
	}
}