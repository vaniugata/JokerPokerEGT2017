#ifndef OUTRO_SCREEN_H
#define OUTRO_SCREEN_H
#include "Screen.h"
#include "Texture.h"
#include "Globals.h"


class OutroScreen : public Screen
{
private:
	Texture m_tBackground;
	Texture m_tCredit;
	SDL_Event* m_ptrEvent;
	eGameState* m_ptrGameState;
	static double m_dCredit;
public:
	OutroScreen(SDL_Renderer* renderer, SDL_Event* ptrEvent, eGameState* gameState);
	~OutroScreen();

	void Draw();
	void Render();
	void HandleEvent();
	void Delay();

	static void SetCredit(double credit);
};
#endif
