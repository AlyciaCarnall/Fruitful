#include "Background.h"
#include "Visualisation.h"

Background::Background(const std::string& name) : Entity(name)
{
}

Background::~Background()
{
}

void Background::Update(const Visualisation &mVis)
{
	mVis.BlitTransparentRender(mGFXname, (int)mPos.x, (int)mPos.y);

	static const HAPI_TKeyboardData& Key = HAPI.GetKeyboardData();

	if ((Key.scanCode[HK_RIGHT]) || Key.scanCode['D'])
		mPos.x += mSpeed;

	if ((Key.scanCode[HK_LEFT]) || Key.scanCode['A'])
		mPos.x -= mSpeed;

	/*if ((Key.scanCode[HK_DOWN]) || Key.scanCode['S'])
		mPos.y += mSpeed;

	if ((Key.scanCode[HK_UP]) || Key.scanCode['W'])
		mPos.y -= mSpeed;*/

}
