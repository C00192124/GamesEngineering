#pragma once
#include "Entity.h"
#include <iostream>

void Entity::update()
{
	for (int i = 0; i < components.size(); i++)
	{
		std::cout << "Component" << std::endl;
	}
}