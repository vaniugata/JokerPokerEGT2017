#ifndef BONUSGAME_H_
#define BONUSGAME_H_

#include "Screen.h"
#include "Card.h"
#include "Texture.h"
#include "Globals.h"
#include "ButtonObject.h"
#include "includesSDL2.h"

class BonusGame: public Screen {

private:
	static int m_win;
	double* m_ptrCredit;
	int m_diceResult;
	int m_resDie1;
	int m_resDie2;

	//Texture objects
	Texture m_tBackgorund;
	Texture m_tChoiceWin;
	Texture m_spriteDieTexture;

	//SDL_Event object pointer
	SDL_Event* m_event;

	//enum eGameState pointer
	eGameState* m_ptrGameState;

	//SDL_Rect arrays
	SDL_Rect m_spriteDie[6];
	SDL_Rect m_ChoiceWin[3];

	//Button objects
	ButtonObject m_buttonX2;
	ButtonObject m_buttonX5;
	ButtonObject m_buttonX10;

	ButtonObject m_btnMusic;
	ButtonObject m_btnMusicPlus;
	ButtonObject m_btnMusicMinus;
	ButtonObject m_btnMusicPause;

	bool m_bShowPlayButton = true;
<<<<<<< HEAD

	//The music that will be played
	Mix_Chunk* ButtonPress = nullptr;
	Mix_Chunk* RollDice = nullptr;
=======
>>>>>>> origin/master

	Music m_mMusic;
	int m_iCounterVolumeMusic;

public:
	BonusGame(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState,
			double* credit);

	virtual ~BonusGame();

	//The music that will be played
	Mix_Chunk* ButtonPress = nullptr;
	Mix_Chunk* RollDice = nullptr;

	//GetCredit
	double* GetCredit();

	//Load Files
	void LoadMusicFiles();
	void LoadDieFiles();
	void LoadChoiceWinFiles();

	void Draw();
	void Render();
	void HandleEvent();

	//logic
	void RenderChoiceWin();
	void RenderDice();

	//Utiliti function
	void delay(Uint32 ms);
	int RandomNumberGenerator();

	//gets and sets
	int getResDie1() const;
	void setResDie1(int resDie1);
	int getResDie2() const;
	void setResDie2(int resDie2);
	static void setWin(int);

	void Close();

};
#endif
