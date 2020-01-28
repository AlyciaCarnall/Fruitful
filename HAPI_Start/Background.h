#pragma once
#include "Entity.h"

class Background : public Entity
{
private:
	//Temp var
	Vector2 mBGpos{ mPos };

public:
	Background(const std::string& name);
	~Background();
	void Update(const Visualisation& mVis) override final;

};

