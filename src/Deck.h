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
	Texture m_tHold;
	Card deckOfCards[54];
	std::vector<Card> hand;

	
public:
	ButtonObject m_currentBtn;
	ButtonObject m_vecCardHold[5];

public:
	int k = 0;
	Deck(SDL_Renderer*);
	void deal();
	void printDeck();

	//getters
	Card getRandomCard();

	ButtonObject* GetHeldCardsButtons();
	std::vector<Card>& GetHand();

	std::vector<Card> sortHand();

	int evaluateHand();
	bool isCardInHand(Card& card);
	bool isJokerHand();
	void RenderCard(SDL_Renderer*,SDL_Rect*,SDL_Rect*);
	void RenderHand(SDL_Renderer*);
	void RenderHoldBtns(SDL_Renderer*);
	void RenderHoldStamps(SDL_Renderer* renderer);
	void initHoldBtns();
	//void isBtnCardClicked();
	



};



#endif 

