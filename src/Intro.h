#ifndef INTRO_H
#define INTRO_H

#include "GameState.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"


class Intro : public GameState
{
private:
	double* m_ptrCredit;
	Texture m_tBackgorund;
	Texture m_tCredit;
	SDL_Event* m_event;
	eGameState* m_ptrGameState;

	ButtonObject m_btnNewGame;
	ButtonObject m_btnResumeGame;
	ButtonObject m_btnCashIn;

public:
	Intro(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState, double* credit);
	~Intro();

	void Draw();
	void Render();
	void HandleEvent();
	void CashIn(double ammount);


};
#endif
