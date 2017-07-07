
#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 600;

const int CARD_WIDTH = 161;
const int CARD_HEIGHT = 242;

const int SPRITE_WIDTH = 131;
const int SPRITE_HEIGHT = 176;

class Cards {
public:
	Cards();
	virtual ~Cards();

	void render();
	void clickCard(int x, int y);
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	TTF_Font* m_font;

	SDL_Texture* m_currentTexture;
	SDL_Texture* m_backgroundTexture;


	SDL_Rect m_gSpriteClips[56];
	bool isClicked[56];
	SDL_Rect m_gSpriteCards[4][14];
	SDL_Rect m_BackToCard;



	void Init();
	void LoadMedia();
	void Close();
};
#endif /* GAME_H_ */
