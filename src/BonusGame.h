#ifndef BONUSGAME_H_
#define BONUSGAME_H_
#include "GameState.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"

class BonusGame: public GameState
{
private:
	double m_dCredit;
	Texture m_tBackgorund;
	Texture m_tChoiceWin;
	Texture m_spriteDieTexture;
	SDL_Event* m_event= nullptr;
	eGameState* m_ptrGameState= nullptr;


	SDL_Rect m_spriteDie[6];
	SDL_Rect m_ChoiceWin[3];

	ButtonObject m_btnX2;
	ButtonObject m_btnX5;
	ButtonObject m_btnX10;

public:
	BonusGame(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState);
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

	void Draw();
	void Render();
	void HandleEvent();


	//logic
	int ResultDice();
	double calculateWin(double credits,int x);
	void Close();

};
#endif
