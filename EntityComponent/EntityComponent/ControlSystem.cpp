#include "ControlSystem.h"

void ControlSystem::update()
{
	std::cout << "ControlSystem Update" << std::endl;
	
	for (int i = 0; i < entities.size(); i++)
	{
		std::vector<Component> vec = entities.at(i).getComponents();
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << "Component" << std::endl;
		}
	}
}