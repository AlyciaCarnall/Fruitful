#include "Player.h"
#include "Visualisation.h"


Player::Player(const std::string& name) : Entity(name)
{
	mSide = eSide::ePlayer;
	SetPosition(Vector2(0, 310));
}

void Player::Update(const Visualisation &mVis)
{
	mVis.BlitTransparentRender(mGFXname, (int)mPos.x, (int)mPos.y);

	static const HAPI_TKeyboardData& Key = HAPI.GetKeyboardData();

	if (((Key.scanCode[HK_RIGHT]) || Key.scanCode['D']) && mPos.x + mVis.getSpriteWidth("Player") < mVis.getScreenWidth())
		mPos.x += mSpeed;

	if (((Key.scanCode[HK_LEFT]) || Key.scanCode['A']) && mPos.x > 0)
		mPos.x -= mSpeed;

	if ((Key.scanCode[HK_SPACE]))
	{
		isOnGround = false;
		mPos.y -= 10;
	}
		
	if (mPos.y + mVis.getSpriteHeight("Player") < 430)
	{
		mPos.y += 5;
	}
	
	int controller{ 0 };
	const HAPI_TControllerData& Controller = HAPI.GetControllerData(controller);

	if (Controller.isAttached)
	{
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_RIGHT])
			mPos.x += mSpeed;
		
		if (Controller.digitalButtons[HK_DIGITAL_DPAD_LEFT])
			mPos.x -= mSpeed;

		if (Controller.digitalButtons[HK_DIGITAL_DPAD_UP])
		{
			isOnGround = false;
			mPos.y -= 10;
		}

		if (mPos.y + mVis.getSpriteHeight("Player") < 430)
		{
			mPos.y += 5;
		}
			
	}
	//The first SetPosition is to put the player on the bottom of the screen
	
	SetPosition(mPos);
}