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
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	JOKERSUIT
} eCardSuit;

typedef enum
{
	EMPTYPOSITION,
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	FIFTH
} eCardPosition;


class Card
{
public:
	friend bool operator<(const Card& oldcard, const Card& newcard);
	friend bool operator==(const Card& leftValue, const Card& rightValue);

private:
	eCardSuit m_cardSuit;
	eCardValue m_cardValue;
	SDL_Rect m_cardRect;
	bool m_bIsHold;
	bool m_isGood;
    eCardPosition m_position;
public:
	Card& operator=(const Card& newcard);

	Card();
	Card(eCardSuit,eCardValue,SDL_Rect,eCardPosition);
	//getters
	eCardSuit getCardSuit()const;
	eCardValue getCardValue()const;
	eCardPosition getCardPosition()const;
	SDL_Rect* getCardRect();
	bool getIsHold();
	bool getIsGood() const;

	//setters
	void setCardSuit(eCardSuit);
	void setCardValue(eCardValue);
	void setCardRect(int,int,int,int);
	void setIsHold(bool);
	void setIsGood(bool);
	void setCardPosition(eCardPosition position);
};


#endif

