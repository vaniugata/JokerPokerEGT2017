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
	int m_iOutroTime;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	//game components
	Texture m_tBackground;
	Texture m_tCredit;
	Texture m_tGameOver;
	PaytableObject* m_paytable;
public:
	Deck* m_ptrDeck;

private:
	std::vector<Evaluation*> m_vecEvaluations;
	std::vector<Evaluation*> m_vecAutoHold;

	//Buttons
	ButtonObject* m_btnCashOut;	
	ButtonObject* m_btnDealDraw;	
	ButtonObject* m_btnMusic;
	ButtonObject* m_btnMusicPlus;
	ButtonObject* m_btnMusicMinus;
	ButtonObject* m_btnMusicPause;
	ButtonObject* m_btnAutoHold;

	bool m_bIsGameOver;
	bool m_bIsBonus;
	int m_iWinIndex;
	bool m_bAutoHold;
	bool m_bShowPlayButton = true;

	int m_iCounterVolumeMusic = 10;

public:
	eGameState m_eGameState;
	SDL_Event m_event;

public:
	Game();
	~Game();

	//getters
	SDL_Renderer* GetRenderer() const;
	double* GetCredit();
	int* GetBet();

	//setters
	void SetBetFromRecovery(); // only if game returns form recovery state
	void SetGameState(eGameState gs);

	void Draw();
	void Render();
	void RenderRound();
	void RenderGameInfo();
	void RenderGameOver();
	void HandleEvent();
	void ProcessKeyInput();
	void ProcessMouseInput();
	static bool SwitchFrame(int time);
	//game logic
	void ProcessRound();

private:
	void InitSDL();
	void Close();
};
#endif
