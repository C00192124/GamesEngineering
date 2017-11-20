#include "RenderSystem.h"

void RenderSystem::update()
{
	std::cout << "RenderSystem Update" << std::endl;
	
	for (int i = 0; i < entities.size(); i++)
	{
		entities.at(i).update();
	}
}