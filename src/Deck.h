#ifndef  DECK_H
#define DECK_H
#include "Card.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include "Texture.h"


class Deck
{
private:
	Texture m_texture;
	Card deckOfCards[54];
	std::vector<Card> hand;
public:
	int k = 0;
	Deck(SDL_Renderer*);
	void deal();
	void printDeck();
	Card getRandomCard();
	void sortHand();
	int evaluateHand();
	bool isCardInHand();
	bool isJokerHand();
	void RenderCard(SDL_Renderer*,SDL_Rect*,SDL_Rect*);
	void RenderHand(SDL_Renderer*);

};



#endif 

