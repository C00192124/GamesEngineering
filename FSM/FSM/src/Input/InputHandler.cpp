#include "Input/InputHandler.h"

//Handles all input before calling execute on the objects
void InputHandler::handleInput(SDL_Event &event) {
	if (event.key.keysym.sym == SDLK_x) buttonX_->execute();
	else if (event.key.keysym.sym == SDLK_y) buttonY_->execute();
}