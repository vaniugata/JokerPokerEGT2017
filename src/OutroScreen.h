#ifndef OUTRO_SCREEN_H
#define OUTRO_SCREEN_H
#include "Screen.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"
#include "Music.h"

class OutroScreen : public Screen
{
private:
	Texture m_tBackground;
	Texture m_tCredit;
	SDL_Event* m_ptrEvent;
	eGameState* m_ptrGameState;
	static double m_dCredit;
	bool m_bShowPlayButton;
	int m_iTextY;
	static int m_iStart;
	static int m_iCurrentTime;
public:
	OutroScreen(SDL_Renderer* renderer, SDL_Event* ptrEvent, eGameState* gameState);
	~OutroScreen();

	//setters
	static void SetTimer(int time);
	static void SetCredit(double credit);
	static void setCurrentTime(int currentTime);

	void Draw();
	void Render();
	void HandleEvent();
	void Delay();
	void AnimText();
};
#endif
