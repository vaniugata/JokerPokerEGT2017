#ifndef CARD_H
#define CARD_H

#include<iostream>

#include "includesSDL2.h"

typedef enum
{
	EMPTY,
	DEUCE,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	JOKER
} eCardValue;

typedef enum
{
	EMPTY,
	DIOMOND,
	SPADE,
	HEART,
	CLUB,
	JOKER
} eCardSuit;


class Card
{
private:
	eCardSuit cardSuit;
	eCardValue cardValue;
public:
	Card(eCardSuit cardSuit ,eCardValue eCardValue);


};


#endif

