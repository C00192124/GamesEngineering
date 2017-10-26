#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Input/InputHandler.h"
#include "Animation/Animation.h"

using namespace std;

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	InputHandler* input = new InputHandler;
	Animation fsm;

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = IMG_LoadTexture(renderer, "idle.bmp");

	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	bool isRunning = true;
	while (isRunning) {

		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				isRunning = false;
			}

			switch (event.type) {
			case SDL_KEYDOWN:
				input->handleInput(event);
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	return 0;

}