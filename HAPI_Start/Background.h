#pragma once
#include "Entity.h"

class Background :	public Entity
{
public:
	Background(const std::string& name);
	~Background();

	void Update(const Visualisation& mVis) override final;

};

