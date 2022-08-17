#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <glad/glad.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace simulator;

int main(int argc, char* argv[]){

	srand(time(NULL));

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	Screen screen;

	if(screen.init() == false) {
		std::cout << "Error Initializing SDL Screen \n";
	}

	Swarm swarm;

	while(true) {

		int elapsed = SDL_GetTicks();

		// screen.clear();

		swarm.update(elapsed);

		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 127.5);
		unsigned char green = (unsigned char) ((1 + cos(elapsed * 0.0004)) * 127.5);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0008)) * 127.5);

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.applyBoxBlur();
		screen.update();

		if(!screen.processEvents()) {
			break;
		}
	}

	screen.close();
	return 0;
}
