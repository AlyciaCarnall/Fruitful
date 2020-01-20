#include "Player.h"
#include "Visualisation.h"

Player::Player(const std::string& name) : Entity(name)
{
	mSide = eSide::ePlayer;
}

void Player::Update(const Visualisation &mVis)
{
	mVis.BlitTransparentRender(mGFXname, (int)mPos.x, (int)mPos.y);

	static const HAPI_TKeyboardData& Key = HAPI.GetKeyboardData();

	if (((Key.scanCode[HK_RIGHT]) || Key.scanCode['D']) && mPos.x + mVis.getSpriteWidth("Player") < mVis.getScreenWidth())
		mPos.x += mSpeed;

	if (((Key.scanCode[HK_LEFT]) || Key.scanCode['A']) && mPos.x > 0)
		mPos.x -= mSpeed;

	int controller{ 0 };
	const HAPI_TControllerData& Controller = HAPI.GetControllerData(controller);

	if (Controller.isAttached)
	{
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_RIGHT])
			mPos.x += mSpeed;
		
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_LEFT])
			mPos.x -= mSpeed;
	}
}
