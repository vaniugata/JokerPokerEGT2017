#include "Deck.h"
#include<iostream>



Deck::Deck()
{
	for (int i = 0; i < 52; i++)
	{
		//int suit = rand() % 4;
		//std::cout << suit << std::endl;
		eCardSuit suit;
		deckOfCards[i].setCardSuit(static_cast<eCardSuit> ((i/13)+1));
		deckOfCards[i].setCardValue(static_cast<eCardValue>((i % 13) + 1));	
		
	}
	Card cardForVector;
	for (int i = 0; i < 5; i++)
	{
		hand.push_back(cardForVector);
	}
	//Joker
	deckOfCards[52].setCardSuit(static_cast<eCardSuit>(5));
	deckOfCards[52].setCardValue(static_cast<eCardValue>(15));
	
	srand(time(0));
		//BackCard
}

void Deck::deal()
{
	
	//for(int i =0;i<5;i++)
	//{ 
	//	if (!(hand[i].getIsHold())) {		
	//	//	std::cout << " sada";
	//		hand[i] = deckOfCards[rand() % 52];
	//	}
	//}
	hand[0].setCardValue(TEN);
	hand[0].setCardSuit(SPADE);

	hand[1].setCardValue(JACK);
	hand[1].setCardSuit(SPADE);

	hand[2].setCardValue(QUEEN);
	hand[2].setCardSuit(SPADE);
	
	hand[3].setCardValue(KING);
	hand[3].setCardSuit(SPADE);

	hand[4].setCardValue(ACE);
	hand[4].setCardSuit(SPADE);

		
}


void Deck::printDeck()
{
	for	(int i = 0; i < 5; i++)
	{
		std::cout << hand[i].getCardSuit();
		std::cout << "  ";
		std::cout << hand[i].getCardValue();
		std::cout << std::endl;
	}
}

Card Deck::getRandomCard()
{
	Card randomCard;
	int randomIndex = rand() % 53;
	randomCard = deckOfCards[randomIndex];
	return randomCard;
}

void Deck::sortHand()
{
	std::sort(hand.begin(), hand.begin()+5);
}

int Deck::evaluateHand()
{
	sortHand();
	int royalFlush, full,fourOfAKind, straight, flush, threeOfKind, pair, KingOrBetter;
	fourOfAKind=royalFlush = full = straight = flush = threeOfKind = pair = KingOrBetter = 0;
	int k = 0;

	//checks for flush
	while (k < 4 && hand[k].getCardSuit() == hand[k + 1].getCardSuit())
		k++;
	if (k == 4)
		flush = 1;

	//checks for straight
	k = 0;
	while (k < 4 && hand[k].getCardValue() == hand[k + 1].getCardValue() - 1)
		k++;
	if (k == 4)
		straight = 1;
	//chech for four of a kind
	for (int i = 0; i < 2; i++)
	{
		k = i;
		while (k < i+3 && hand[k].getCardValue() == hand[k + 1].getCardValue())
			k++;
		if (k == i+3)
			fourOfAKind = 1;
	}
	//check for three
	if (!fourOfAKind) {
		for (int i = 0; i < 3; i++)
		{
			k = i;
			while (k < i + 2 && hand[k].getCardValue() == hand[k + 1].getCardValue())
			{
				k++;
			}
			if (k == i + 2)
			{
				threeOfKind = 1;
				if (i == 0)
				{
					if (hand[3].getCardValue() == hand[4].getCardValue()) {
						full = 1;
					}
				}
				else if (i == 1) {
					if (hand[0].getCardValue() == hand[4].getCardValue()) {
						full = 1;
					}
				}
				else {
					if (hand[0].getCardValue() == hand[1].getCardValue())
						full = 1;
				}
			}
		
				}
			}
	if (straight && flush &&hand[0].getCardValue() == TEN) {
		return 10;
	}
if (straight && flush)
{
	return 9;
}
else if (fourOfAKind) {
	return 8;
}
else if (full) {
	return 7;
}
else if (flush) {
	return 6;
}
else if (straight) {
	return 5;
}
else if (threeOfKind) {
	return 4;
}
for (k = 0; k < 4; k++) {
	if (hand[k].getCardValue() == hand[k + 1].getCardValue())
		pair++;
}
if (pair == 2) {
	return 3;
}
else if (pair) {
	return 2;
}
else return 1;
}
