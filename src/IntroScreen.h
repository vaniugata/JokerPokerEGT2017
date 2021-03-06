#ifndef INTRO_H
#define INTRO_H

#include "Screen.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"
#include "Music.h"
#include "Card.h"
#include <vector>
using std::vector;

class IntroScreen : public Screen
{
private:
	double* m_ptrCredit;
	int* m_ptrBet;
	std::vector<Card>* m_ptrHand;
	Texture m_tBackgorund;
	Texture m_tCredit;
	Texture m_tInfo;
	SDL_Event* m_ptrEvent;
	eGameState* m_ptrGameState;

	ButtonObject m_btnNewGame;
	ButtonObject m_btnResumeGame;
	ButtonObject m_btnCashIn;
	ButtonObject m_btnInfo;

	ButtonObject m_btnMusic;
	ButtonObject m_btnMusicPlus;
	ButtonObject m_btnMusicMinus;
	ButtonObject m_btnMusicPause;

	bool m_bShowInfo = false;
	bool m_bShowPlayButton = true;
	int m_iCounterVolumeMusic = 10;

public:
	IntroScreen(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState, 
		double* credit, int* bet, std::vector<Card>* hand);
	~IntroScreen();

	void Draw();
	void Render();
	void HandleEvent();
	void CashIn(double ammount);
	void RenderInfoWindow();
	void EvaluateInfoRendering();
};
#endif
