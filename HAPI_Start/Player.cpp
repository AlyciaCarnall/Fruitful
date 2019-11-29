#include "Player.h"

Player::Player(const std::string& name) : Entity(mGFXname)
{

}

void Player::Update()
{
	static const HAPI_TKeyboardData& Key = HAPI.GetKeyboardData();

	if ((Key.scanCode[HK_RIGHT]) || Key.scanCode['D'])
		mPos.x += mSpeed;

	if ((Key.scanCode[HK_LEFT]) || Key.scanCode['A'])
		mPos.x -= mSpeed;

	if ((Key.scanCode[HK_DOWN]) || Key.scanCode['S'])
		mPos.y += mSpeed;

	if ((Key.scanCode[HK_UP]) || Key.scanCode['W'])
		mPos.y -= mSpeed;

	int controller{ 0 };
	const HAPI_TControllerData& Controller = HAPI.GetControllerData(controller);

	if (Controller.isAttached)
	{
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_RIGHT])
		{
			mPos.x += mSpeed;
		}
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_LEFT])
		{
			mPos.x -= mSpeed;
		}
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_DOWN])
		{
			mPos.y += mSpeed;
		}
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_UP])
		{
			mPos.y -= mSpeed;
		}
	}
}
