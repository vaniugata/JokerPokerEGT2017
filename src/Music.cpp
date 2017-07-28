/*
* Music.cpp
*
<<<<<<< HEAD
*  Created on: 18.07.2017 �.
=======
*  Created on: 18.07.2017 �.
>>>>>>> origin/master
*      Author: Borqna
*/

#include "Music.h"

Mix_Music* Music::Backgraund = nullptr;
Mix_Chunk* Music::Button = nullptr;
Mix_Chunk* Music::Cards = nullptr;
Mix_Chunk* Music::Outro = nullptr;
Mix_Chunk* Music::ButtonBonus= nullptr;
Mix_Chunk* Music::RollDice= nullptr;
Mix_Chunk* Music::winning = nullptr;

Music::Music()
{

}

Music::~Music()
{
	Free();
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
void Music::setButtonBonus(Mix_Chunk* buttonBonus) {
	ButtonBonus = buttonBonus;
}
void Music::setRollDice( Mix_Chunk* rollDice) {
	RollDice = rollDice;
}
void Music::setWinning( Mix_Chunk* winning) {
	RollDice = winning;
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
Mix_Chunk* Music::getButtonBonus(){
	return ButtonBonus;
}
Mix_Chunk* Music::getRollDice(){
	return RollDice;
}
Mix_Chunk* Music::getWinning(){
	return winning;
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

	ButtonBonus= Mix_LoadWAV("ResourcesMusic/ButtonPress.wav");
	if(ButtonBonus == nullptr) {std::cout << Mix_GetError() << "\n";}

	RollDice = Mix_LoadWAV("ResourcesMusic/RollDice.wav");
	if(RollDice == nullptr){std::cout << Mix_GetError() << "\n";}

	winning = Mix_LoadWAV("ResourcesMusic/Winning.wav");
	if(winning == nullptr){std::cout << Mix_GetError() << "\n";}
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

	Mix_FreeChunk(ButtonBonus);
	ButtonBonus = nullptr;

	Mix_FreeChunk(RollDice);
	RollDice = nullptr;
	Mix_FreeChunk(winning);
	winning = nullptr;
}




