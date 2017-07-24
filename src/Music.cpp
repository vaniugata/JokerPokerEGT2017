#include "Music.h"
#include <iostream>
using std::cout;

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

	Button = Mix_LoadWAV("ResourcesMusic/confirm.wav");
	if(Button == nullptr) { std::cout << " Can't load confirm.wav" << Mix_GetError(); }

	Cards = Mix_LoadWAV("ResourcesMusic/cards.wav");
	if(Cards == nullptr) { std::cout << Mix_GetError(); }

	Outro = Mix_LoadWAV("ResourcesMusic/outro.wav");
	if(Outro == nullptr) { std::cout << Mix_GetError(); }
}
