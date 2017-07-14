#ifndef BONUSGAME_H_
#define BONUSGAME_H_
#include "GameState.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"

class BonusGame: public GameState
{
private:
	Texture m_tBackgorund;//	Texture m_texture;
	SDL_Event* m_event;
	eGameState* m_ptrGameState;

	ButtonObject m_ChoiceWin;
	ButtonObject m_btnX2;
	ButtonObject m_btnX5;
	ButtonObject m_btnX10;

public:
	BonusGame(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState);
	virtual~BonusGame();

	//The music that will be played
	Mix_Chunk* ButtonPress = nullptr;
	Mix_Chunk* RollDice = nullptr;


	void Draw();
	void Render();
	void HandleEvent();

	void LoadMusicFiles();

	//logic
	int ResultDice();
	void ProcessMouseWin();
	double calculateWin(double credits,int x);
	void Close();

};
#endif
