/*
* Music.h
*
<<<<<<< HEAD
*  Created on: 18.07.2017 ã.
=======
*  Created on: 18.07.2017 ï¿½.
>>>>>>> origin/master
*      Author: Borqna
*/

#ifndef SRC_MUSIC_H_
#define SRC_MUSIC_H_
using namespace std;
#include"Screen.h"
#include "includesSDL2.h"
#include<iostream>
#include <string>

class Music {

public:
	Music();
	virtual ~Music();

	static void setBackgraund(Mix_Music* music);
	static void setButton(Mix_Chunk* buttonMusic);
	static void setCards(Mix_Chunk* cardsButton);
	static void setOutro(Mix_Chunk* outroMusic);

	static Mix_Music* getBackgraund();
	static Mix_Chunk* getButton();
	static Mix_Chunk* getCards();
	static Mix_Chunk* getOutro();

	static void LoadMusic();
	static void Free();

private:

	static Mix_Music* Backgraund;
	static Mix_Chunk* Button;
	static Mix_Chunk* Cards;
	static Mix_Chunk* Outro;
};

#endif /* SRC_MUSIC_H_ */
