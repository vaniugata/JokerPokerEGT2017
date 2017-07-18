#ifndef BONUSGAME_H_
#define BONUSGAME_H_

#include "Scene.h"
#include "Card.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"
#include "includesSDL2.h"

class BonusGame: public Scene
{

public:
	BonusGame(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState,
			double* credit);

	virtual ~BonusGame();

	//The music that will be played
	Mix_Chunk* ButtonPress = nullptr;
	Mix_Chunk* RollDice = nullptr;

	double* GetCredit();
	void LoadMusicFiles();
	void LoadDieFiles();
	void LoadChoiceWinFiles();

	void Draw();
	void Render();
	void HandleEvent();

	//logic
	void RenderChoiceWin();
	int RandomNumberGenerator();
	void delay(Uint32 ms);

	void RenderDice();
	int ResultDice();
	double calculateWin(double credits, int x);

	void Close();
	int getDiceResult() const;
	void setDiceResult(int diceResult);
	int getResDie1() const;
	void setResDie1(int resDie1);
	int getResDie2() const;
	void setResDie2(int resDie2);

private:
	double* m_ptrCredit;
	int m_diceResult;
	int m_resDie1;
	int m_resDie2;

	Texture m_tBackgorund;
	Texture m_tCredit;
	SDL_Event* m_event;
	eGameState* m_ptrGameState;

	Texture m_tChoiceWin;
	Texture m_spriteDieTexture;

	SDL_Rect m_spriteDie[6];
	SDL_Rect m_ChoiceWin[3];

	ButtonObject m_buttonX2;
	ButtonObject m_buttonX5;
	ButtonObject m_buttonX10;

};
#endif
