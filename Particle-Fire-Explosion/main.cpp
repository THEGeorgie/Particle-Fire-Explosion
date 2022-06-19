#include "SDL.h"
#include "Screen.h"
#undef main
#include <iostream>
using namespace std;
using namespace GJ;
int main() {
	bool quit = false;
	SDL_Event event;
	
	Screen screen;

	if (screen.init() == false) {
		cout << "Error intilasing SDL" << endl;
	}

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

	screen.close();


	return 0;
}

