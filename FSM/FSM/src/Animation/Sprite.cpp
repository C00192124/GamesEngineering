#include "Animation\Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer) {
	
	texture = IMG_LoadTexture(renderer, "idle.bmp");

	imageRect.x = 0;
	imageRect.y = 0;
	imageRect.w = 157;
	imageRect.h = 115;

	frameRect.x = 0;
	frameRect.y = 0;
	frameRect.w = 64;
	frameRect.h = 48;

}

Sprite::~Sprite() {}

void Sprite::Render(SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer, texture, &imageRect, &frameRect);
}

void Sprite::Animate() {

	imageRect.x = 1100;

	if (imageRect.x = )
}