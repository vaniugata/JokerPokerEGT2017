#ifndef BONUSGAME_H_
#define BONUSGAME_H_
#include "Texture.h"
#include "ButtonObject.h"
#include "includesSDL2.h"
#include "Globals.h"
#include <string>
class BonusGame
{
private:
	Texture m_texture;
	Texture m_tText;
	Texture m_bonusText;
	TTF_Font* m_font;

	ButtonObject m_ChoiceWin;
	ButtonObject m_btnX2;
	ButtonObject m_btnX5;
	ButtonObject m_btnX10;

public:
	BonusGame(SDL_Renderer* renderer);
	virtual~BonusGame();
	//The music that will be played
	Mix_Chunk *ButtonPress = nullptr;
	Mix_Chunk *RollDice = nullptr;
	Mix_Chunk *Winning = nullptr;
	//getters
	ButtonObject& GetChoiceWin();
	ButtonObject& GetWinX2();
	ButtonObject& GetWinX5();
	ButtonObject& GetWinX10();

	void InitFont(std::string path);
	void Render(SDL_Renderer* renderer);
	void RenderWin(SDL_Renderer* renderer);
	void RenderCalculateWin(SDL_Renderer * renderer);
	void LoadMusicFiles();
	//logic
	int ResultDice();
	double calculateWin(double credits,int x);
	void Close();


};
#endif
