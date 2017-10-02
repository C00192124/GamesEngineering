#pragma once
#include <SDL.h>
#include <iostream>

class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command() {}
};

class JumpCommand : public Command {
public:
	virtual void execute() { std::cout << "Jump" << std::endl; }
};

class FireCommand : public Command {
public:
	virtual void execute() { std::cout << "Fire" << std::endl; }
};

class InputHandler {
public:
	void handleInput(SDL_Event &event);
private:
	Command* buttonX_ = new JumpCommand();
	Command* buttonY_ = new FireCommand();
};