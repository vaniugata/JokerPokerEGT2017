#ifndef CARD_H
#define CARD_H

#include<iostream>

#include "includesSDL2.h"

typedef enum 
{
	EMPTYVALUE,
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
	JOKERVALUE
} eCardValue;

typedef enum 
{
	EMPTYSUIT,
	DIOMOND,
	SPADE,
	HEART,
	CLUB,
	JOKERSUIT
} eCardSuit;



class Card
{
private:
	eCardSuit m_cardSuit;
	eCardValue m_cardValue;
	SDL_Rect m_cardRect;
	bool m_bIsHold;
public:
	Card& operator=(const Card& newcard);
	Card();
	Card(eCardSuit,eCardValue,SDL_Rect);
	eCardSuit getCardSuit()const;
	eCardValue getCardValue()const;
	SDL_Rect getCardRect();
	void setCardSuit(eCardSuit);
	void setCardValue(eCardValue);
	void setCardRect(SDL_Rect);
	void setIsHold(bool);
	bool getIsHold();
    friend bool operator<(const Card& oldcard,const Card& newcard);
	//friend bool operator==(eCardValue leftValue, eCardValue rightValue);
	




};


#endif

