#ifndef GAME_H
#define GAME_H

#include "Texture.h"
#include "Globals.h"
#include "PaytableObject.h"
#include "BonusGame.h"
#include "WinBonus.h"
#include "includesSDL2.h"
#include "Deck.h"

class Game
{
private:
	double m_dCredit;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	//game components
	Texture* m_tBackground;
	PaytableObject* m_paytable;
	Deck* deck;

public:
	eGameState m_eGameState;
	SDL_Event m_event;

public:
	Game();
	~Game();

	SDL_Renderer* GetRenderer() const;
	double* GetCredit();

	void SetGameState(eGameState gs);

	void Draw();
	void Render();
	void HandleEvent();
	void ProcessKeyInput();
	void ProcessMouseInput();

private:
	void InitSDL();
	void Close();

};
#endif
