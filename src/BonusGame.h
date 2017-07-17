#ifndef BONUSGAME_H_
#define BONUSGAME_H_

#include "Scene.h"

#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"


class BonusGame: public Scene
{
private:
	double* m_ptrCredit;
	Texture m_tBackgorund;
	Texture m_tChoiceWin;
	Texture m_spriteDieTexture;
	SDL_Event* m_event;
	eGameState* m_ptrGameState;

	SDL_Rect m_spriteDie[6];
	SDL_Rect m_ChoiceWin[3];
	ButtonObject m_buttonX2;
	ButtonObject m_buttonX5;
	ButtonObject m_buttonX10;

public:
	BonusGame(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState, double* credit);

	virtual~BonusGame();

	//The music that will be played
	Mix_Chunk* ButtonPress = nullptr;
	Mix_Chunk* RollDice = nullptr;
	double* GetCredit();
	void LoadMusicFiles();
	void LoadDieFiles();
	void RenderDice();
	void RenderChoiceWin();
	void LoadChoiceWinFiles();

	void DoAnimation();
	void TimerBonus();


	void Draw();
	void Render();
	void HandleEvent();


	//logic
	int ResultDice();
	double calculateWin(double credits,int x);
	void Close();

};
#endif
