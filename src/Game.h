#ifndef GAME_H
#define GAME_H
#include "includesSDL2.h"

#include "Texture.h"
#include "Globals.h"
#include "PaytableObject.h"
#include "BonusGame.h"
#include "WinBonus.h"
#include "Deck.h"
#include "Evaluation\Evaluation.h"

class Game 
{
private:
	double m_dCredit;
	int m_iBet;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	//game components
	//Texture objects
	Texture m_tBackground;
	Texture m_tCredit;
	Texture m_tGameOver;
	//PaytableObject objects
	PaytableObject* m_paytable;
	//Deck objects
	Deck* m_ptrDeck;

	std::vector<Evaluation*> m_vecEvaluations;
	//Button objects
	ButtonObject* m_btnCashOut;//Button CashOut
	ButtonObject* m_btnDealDraw;//Button Deal/Draw

	bool m_bIsGameOver;
	bool m_bIsBonus;
	int m_iWinIndex;

public:
	eGameState m_eGameState;
	SDL_Event m_event;


public:
	Game();
	~Game();

	SDL_Renderer* GetRenderer() const;
	double* GetCredit();
	int* GetBet();
	void SetGameState(eGameState gs);

	void Draw();
	void Render();
	void RenderRound(Deck* deck);
	void RenderGameInfo();
	void RenderGameOver();
	void HandleEvent();
	void ProcessKeyInput();
	void ProcessMouseInput();
	//game logic
	void ProcessRound();

private:
	void InitSDL();
	void Close();

};
#endif
