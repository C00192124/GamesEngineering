#include "Animation/Jump.h"

Jump::Jump() {

}

Jump::~Jump() {

}

void Jump::idle(Animation* a) {
	std::cout << "idling" << std::endl;
	a->setCurrent(new Jump());
	delete this;
}