#pragma once
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Component.h"

class ControlSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update();
};