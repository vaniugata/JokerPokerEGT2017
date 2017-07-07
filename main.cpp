//============================================================================
// Name        : 0000000RossitsaTasheva_final�xam.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Cards.h"
using namespace std;

int main(int args, char* argc[]) {
	Cards game;

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				int x, y;
				SDL_GetMouseState(&x, &y);
				game.clickCard(x, y);
			}
		}

		game.render();

	}
	return 0;
}
