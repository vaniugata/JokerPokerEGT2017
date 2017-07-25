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
	eCardSuit getCardSuit()const;
	eCardValue getCardValue()const;
	SDL_Rect* getCardRect();
	void setCardSuit(eCardSuit);
	void setCardValue(eCardValue);
	void setCardRect(int,int,int,int);
	void setIsHold(bool);
	bool getIsHold();

	void setIsGood(bool);
	bool getIsGood();

	void setCardPosition(eCardPosition position);
	eCardPosition getCardPosition()const;

    friend bool operator<(const Card& oldcard,const Card& newcard);
	friend bool operator==(const Card& leftValue,const Card& rightValue);
	




};


#endif

