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
	mVis.BlitFastRender(mGFXname, mPos.x, mPos.y);

}
