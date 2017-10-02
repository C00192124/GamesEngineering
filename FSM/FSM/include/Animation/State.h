#pragma once
#include "Animation.h"

class State {
public:
	virtual void idle(Animation* a) {
		std::cout << "Idling" << std::endl;
	}
	virtual void jumping(Animation* a) {
		std::cout << "Jumping" << std::endl;
	}
	virtual void firing(Animation* a) {
		std::cout << "Firing" << std::endl;
	}
};