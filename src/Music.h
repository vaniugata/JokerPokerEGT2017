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



class Music
{


public:
	Music();
	virtual ~Music();



  void setBackgraund(Mix_Music* music);
  void setButton(Mix_Chunk* buttonMusic);
  void setCards(Mix_Chunk* cardsButton);
  void setOutro(Mix_Chunk* outroMusic);


  Mix_Music* getBackgraund();
  Mix_Chunk* getButton();
  Mix_Chunk* getCards();
  Mix_Chunk* getOutro();

  void LoadMusic();


private:


    Mix_Music* Backgraund = nullptr;
	Mix_Chunk* Button = nullptr;
	Mix_Chunk* Cards = nullptr;
	Mix_Chunk* Outro= nullptr;
};

#endif /* SRC_MUSIC_H_ */
