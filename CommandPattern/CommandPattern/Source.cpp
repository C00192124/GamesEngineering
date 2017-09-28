#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

//Using a command pattern allows decoupling so that 
//commands can be passed to multiple recievers
//This also means that the invoker class is more reusable
class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command() {}
};

class JumpCommand : public Command {
public:
	virtual void execute() { cout << "Jump" << endl; }
};

class FireCommand : public Command {
public:
	virtual void execute() { cout << "Fire" << endl; }
};

class InputHandler {
public:
	void handleInput(SDL_Event &event);
private:
	Command* buttonX_ = new JumpCommand();
	Command* buttonY_ = new FireCommand();
};

//Handles all input before calling execute on the objects
void InputHandler::handleInput(SDL_Event &event) {
	if (event.key.keysym.sym == SDLK_x) buttonX_->execute();
	else if (event.key.keysym.sym == SDLK_y) buttonY_->execute();
}

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	InputHandler* input = new InputHandler;
	
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