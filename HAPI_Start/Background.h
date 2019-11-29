#pragma once
#include "Entity.h"
class Background :	public Entity
{
public:
	Background(std::string& name);
	~Background();

	void Update() override final;

};

