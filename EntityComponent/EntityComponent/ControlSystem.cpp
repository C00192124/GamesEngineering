#include "ControlSystem.h"

void ControlSystem::update()
{
	std::cout << "ControlSystem Update" << std::endl;
	
	for (int i = 0; i < entities.size(); i++)
	{
		entities.at(i).update();
	}
}