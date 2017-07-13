#ifndef  DECK_H
#define DECK_H
#include "Card.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>




class Deck
{
private:
	Card deckOfCards[54];
	std::vector<Card> hand;
public:
	int k = 0;
	Deck();
	void deal();
	void printDeck();
	Card getRandomCard();
	void sortHand();
	int evaluateHand();
	bool isCardInHand();
	bool isJokerHand();
};



#endif 

