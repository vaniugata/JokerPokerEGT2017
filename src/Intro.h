#ifndef INTRO_H
#define INTRO_H

#include "GameState.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"

class Intro : public GameState
{
private:
	Texture m_tBackgorund;
	SDL_Event* m_event;
	eGameState* m_ptrGameState;

	ButtonObject m_btnNewGame;

public:
	Intro(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState);
	~Intro();

	void Draw();
	void Render();
	void HandleEvent();
	void ProcessMouseInput();
};
#endif
