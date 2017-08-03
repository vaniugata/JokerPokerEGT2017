#ifndef SRC_MUSIC_H_
#define SRC_MUSIC_H_
#include "includesSDL2.h"
#include "Globals.h"
#include<iostream>

class Music
{
public:
	Music();
	virtual ~Music();

	static void setBackgraund(Mix_Music* music);
	static void setButton(Mix_Chunk* buttonMusic);
	static void setCards(Mix_Chunk* cardsButton);
	static void setOutro(Mix_Chunk* outroMusic);
	static void setButtonBonus(Mix_Chunk* buttonBonus);
	static void setRollDice(Mix_Chunk* rollDice);
	static void setWinning(Mix_Chunk* winning);


	static Mix_Music* getBackgraund();
	static Mix_Chunk* getButton();
	static Mix_Chunk* getCards();
	static Mix_Chunk* getOutro();
	static Mix_Chunk* getRollDice();
	static Mix_Chunk* getButtonBonus();
	static Mix_Chunk* getWinning();
	static void LoadMusic();
	static void Free();

	static void PlayPaytableSoundEffect(int i);

private:

	static Mix_Music* Backgraund;
	static Mix_Chunk* Button;
	static Mix_Chunk* Cards;
	static Mix_Chunk* Outro;
	static Mix_Chunk* ButtonBonus;
	static Mix_Chunk* RollDice;
	static Mix_Chunk* winning;

	//paytable sounds
	static Mix_Chunk* m_paytableSfx[WINS];
};

#endif /* SRC_MUSIC_H_ */
