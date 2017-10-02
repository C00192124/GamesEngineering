#include "Animation/Fire.h"

Fire::Fire() {

}

Fire::~Fire() {

}

void Fire::idle(Animation* a) {
	std::cout << "idling" << std::endl;
	a->setCurrent(new Fire());
	delete this;
}