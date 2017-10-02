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
	}

	SDL_Quit();
	return 0;

}