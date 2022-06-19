#include "SDL.h"
#include "Screen.h"
#undef main
#include <iostream>
using namespace std;
using namespace GJ;
int main() {
	
	Screen screen;

	if (screen.init() == false) {
		cout << "Error intilasing SDL" << endl;
	}

	while (true) {
		//Update Particles
		//Draw Particles
		//Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}

	}

	screen.close();


	return 0;
}

