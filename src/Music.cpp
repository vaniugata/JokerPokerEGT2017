/*
* Music.cpp
*
<<<<<<< HEAD
*  Created on: 18.07.2017 ã.
=======
*  Created on: 18.07.2017 ï¿½.
>>>>>>> origin/master
*      Author: Borqna
*/

#include "Music.h"

Mix_Music* Music::Backgraund = nullptr;
Mix_Chunk* Music::Button = nullptr;
Mix_Chunk* Music::Cards = nullptr;
Mix_Chunk* Music::Outro = nullptr;

Music::Music() {

}

Music::~Music() {

	// TODO Auto-generated destructor stub

}

void Music::setBackgraund(Mix_Music* music) {
	Backgraund = music;

}
void Music::setButton(Mix_Chunk* buttonMusic) {
	Button = buttonMusic;
}
void Music::setCards(Mix_Chunk* cardsMusic) {
	Cards = cardsMusic;
}
void Music::setOutro(Mix_Chunk* outroMusic) {
	Outro = outroMusic;
}

Mix_Music* Music::getBackgraund() {
	return Backgraund;
}
Mix_Chunk* Music::getButton() {
	return Button;
}
Mix_Chunk* Music::getCards() {
	return Cards;
}
Mix_Chunk* Music::getOutro() {
	return Outro;
}


void Music::LoadMusic()
{
	Backgraund = Mix_LoadMUS("ResourcesMusic/backgroundMusic.mp3");
	if(Backgraund == nullptr) { std::cout << Mix_GetError() << "\n"; }

	Button = Mix_LoadWAV("ResourcesMusic/buttons.wav");
	if(Button == nullptr) { std::cout << Mix_GetError() << "\n"; }

	Cards = Mix_LoadWAV("ResourcesMusic/cards.wav");
	if(Cards == nullptr) { std::cout << Mix_GetError() << "\n"; }

	Outro = Mix_LoadWAV("ResourcesMusic/outro.wav");
	if(Outro == nullptr) { std::cout << Mix_GetError() << "\n"; }
}

void Music::Free()
{
	Mix_FreeMusic(Backgraund);
	Backgraund = nullptr;

	Mix_FreeChunk(Button);
	Button = nullptr;

	Mix_FreeChunk(Cards);
	Cards = nullptr;

	Mix_FreeChunk(Outro);
	Outro = nullptr;
}
