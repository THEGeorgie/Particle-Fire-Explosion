#include "SDL.h"
#undef main
#include <iostream>
using namespace std;

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
		cout << "Sdl init failed... " << endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (window == NULL) {
		SDL_Quit();
		return 2;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (renderer == NULL) {
		cout << "Renderer not created" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	if (texture == NULL) {
		cout << "Texture not created" << endl;

		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	SDL_UpdateTexture(texture, 0, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, 0, 0);
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event event;
	
	while (!quit) {
		//Update Particles
		//Draw Particles
		//Check for messages/events

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	
	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

