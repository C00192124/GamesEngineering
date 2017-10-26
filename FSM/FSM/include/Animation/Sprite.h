#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Sprite {
public:
	Sprite(SDL_Renderer* renderer);
	~Sprite();
	void Animate();
	void Render(SDL_Renderer* renderer);

private:
	int currentFrame;
	int oldTime;

	SDL_Rect imageRect;
	SDL_Rect frameRect;
	SDL_Texture* texture;

};