#ifndef  DECK_H
#define DECK_H
#include "Card.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include "Texture.h"
#include "ButtonObject.h"


class Deck
{
private:
	Texture m_texture;
	Card deckOfCards[54];
	std::vector<Card> hand;
	std::vector<ButtonObject> m_vecCardHold;

	ButtonObject m_currentBtn;
public:
	int k = 0;
	Deck(SDL_Renderer*);
	void deal();
	void printDeck();

	//getters
	Card getRandomCard();
	std::vector<ButtonObject>& GetHeldCardsButtons();
	std::vector<Card>& GetHand();

	void sortHand();
	int evaluateHand();
	bool isCardInHand(Card& card);
	bool isJokerHand();
	void RenderCard(SDL_Renderer*,SDL_Rect*,SDL_Rect*);
	void RenderHand(SDL_Renderer*);
	void RenderHoldButtons(SDL_Renderer* renderer);
	void CreateHoldButtons();

};



#endif 

