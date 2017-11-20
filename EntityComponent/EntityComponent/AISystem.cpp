#include "AISystem.h"

void AISystem::update() {

	std::cout << "AISystem Update" << std::endl;

	for (int i = 0; i < entities.size(); i++)
	{
		entities.at(i).update();
	}
}