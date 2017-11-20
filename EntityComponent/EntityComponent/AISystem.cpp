#include "AISystem.h"

void AISystem::update() {

	std::cout << "AISystem Update" << std::endl;

	for (int i = 0; i < entities.size(); i++)
	{
		std::vector<Component> vec = entities.at(i).getComponents();
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << "Component" << std::endl;
		}
	}
}