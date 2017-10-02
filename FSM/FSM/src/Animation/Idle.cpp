#include "Animation/Idle.h"

Idle::Idle() {

}

Idle::~Idle() {

}

void Idle::jumping(Animation* a) {
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Idle::firing(Animation* a) {
	std::cout << "Firing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}