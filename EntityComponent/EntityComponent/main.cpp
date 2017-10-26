#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include <thread>
#include "Component.h"
#include "Entity.h"
#include "HealthComponent.h"
#include "ControlComponent.h"
#include "PositionComponent.h"
#include "AISystem.h"
#include "RenderSystem.h"
#include "ControlSystem.h"

using namespace std;

Entity player;
Entity alien;
Entity dog;
Entity cat;
HealthComponent hc;
ControlComponent cc;
PositionComponent pc;
AISystem ais;
ControlSystem cs;
RenderSystem rs;

int main(int argc, char* argv[])
{
	
	//Player Components
	player.addComponent(hc);
	player.addComponent(cc);
	player.addComponent(pc);

	//Alien Components
	alien.addComponent(hc);
	alien.addComponent(pc);

	//Dog Components
	dog.addComponent(hc);
	dog.addComponent(pc);

	//Cat components
	cat.addComponent(hc);
	cat.addComponent(pc);

	//Systems
	ais.addEntity(player);
	rs.addEntity(player);
	cs.addEntity(player);

	bool gameRunning = true;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_Window* window;
	window = SDL_CreateWindow("ECS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	while (gameRunning)
	{
		SDL_Event event;
		ais.update();
		rs.update();
		cs.update();

		while (SDL_PollEvent(&event));
		{
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_UP)
				{

				}

			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	return 0;
}