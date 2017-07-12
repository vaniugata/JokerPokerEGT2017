#ifndef GAME_H
#define GAME_H

#include "Texture.h"
#include "Globals.h"
#include "PaytableObject.h"
#include "BonusGame.h"
#include "includesSDL2.h"


class Game
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	//game components
	Texture* m_tBackground;
	PaytableObject* m_paytable;

	//--------R----------
	BonusGame* m_bonus;
	//---------------------

public:
	eGameState m_eGameState;
	SDL_Event m_event;

public:
	Game();
	~Game();

	SDL_Renderer* GetRenderer() const;

	void SetGameState(eGameState gs);

	void Draw();
	void Render();
	void HandleEvent();
	void ProcessKeyInput();
	void ProcessMouseInput();
	//--------R---------
	void RenderBonusGame();
	void ProcessMouseWin();
	void RenderBonusWin();
		//---------------------
private:
	void InitSDL();
	void Close();

};
#endif
