#include "Animation/Animation.h"
#include "Animation/Idle.h"

Animation::Animation() {
	current = new Idle();
}

void Animation::idle() {
	current->idle(this);
}

void Animation::jumping() {
	current->jumping(this);
}

void Animation::firing() {
	current->firing(this);
}