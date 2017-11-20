#pragma once
#include <vector>
#include <iostream>
#include "Entity.h"

class AISystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update();
};