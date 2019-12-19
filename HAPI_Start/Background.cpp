#include "Background.h"
#include "Visualisation.h"

Background::Background(const std::string& name) : Entity(name)
{
}

Background::~Background()
{
}

void Background::Update(const Visualisation& mVis)
{
	//Renders the sprite twice
	mVis.BlitTransparentRender(mGFXname, (int)mBGpos.x, (int)mBGpos.y);
	mVis.BlitTransparentRender(mGFXname, (int)mPos.x, (int)mPos.y);
	
	//Gets keyboard data
	static const HAPI_TKeyboardData& Key = HAPI.GetKeyboardData();

	//If key pressed, background will move and constantly scroll
	if ((Key.scanCode[HK_RIGHT]) || Key.scanCode['D'])
	{
		mPos.x += mSpeed;
		mBGpos.x += mSpeed;

		if (mPos.x >= mVis.getScreenWidth())
		{
			mPos.x = 0;
			mBGpos.x = 0;
		}
			
		if (mPos.x > 0)
			mBGpos = { mPos.x - mVis.getSpriteWidth("Background"), mPos.y }; //left
		
	}

	if ((Key.scanCode[HK_LEFT]) || Key.scanCode['A'])
	{
		mPos.x -= mSpeed;
		mBGpos.x -= mSpeed;

		if (mPos.x <= -mVis.getScreenWidth())
		{
			mPos.x = 0;
			mBGpos.x = 0;
		}
			
		if (mPos.x <= 0)
			mBGpos = { mPos.x + mVis.getSpriteWidth("Background"), mPos.y }; //right
	}
		
}
