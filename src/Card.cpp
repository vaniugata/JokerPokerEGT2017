#include "Card.h"

Card & Card::operator=(const Card & newcard)
{
	if (this != &newcard)
	{
		this->m_cardSuit = newcard.m_cardSuit;
		this->m_cardValue = newcard.m_cardValue;
		this->m_cardRect.x = newcard.m_cardRect.x;
		this->m_cardRect.y = newcard.m_cardRect.y;
		this->m_cardRect.w = newcard.m_cardRect.w;
		this->m_cardRect.h = newcard.m_cardRect.h;
		this->m_position = newcard.m_position;
		this->m_bIsHold = newcard.m_bIsHold;
		this->m_isGood = newcard.m_isGood;
	}
	return *this;
}

Card::Card()
{
	this->m_cardSuit = EMPTYSUIT;
	this->m_cardValue = EMPTYVALUE;
	this->m_position = EMPTYPOSITION;
	this->m_bIsHold = false;
	this->m_isGood = false;
}

Card::Card(eCardSuit cardSuit,eCardValue cardValue,SDL_Rect rect,eCardPosition position,
	bool isHold, bool isGood)
{
	    this->m_cardSuit = cardSuit;
		this->m_cardValue = cardValue;
		this->m_cardRect = rect;
		this->m_position = position;
		this->m_bIsHold = isHold;
		this->m_isGood = isGood;
}

eCardSuit Card::getCardSuit()const
{
	return this->m_cardSuit;
}

eCardValue Card::getCardValue()const
{
	return this->m_cardValue;
}

void Card::setCardSuit(eCardSuit suit)
{
	this->m_cardSuit = suit;
}

void Card::setCardValue(eCardValue value)
{
	this->m_cardValue = value;
}

void Card::setCardRect(int x,int y,int w,int h)
{
	this->m_cardRect.x=x;
	this->m_cardRect.y = y;
	this->m_cardRect.w = w;
	this->m_cardRect.h = h;
}

void Card::setIsHold(bool isHold)
{
	this->m_bIsHold = isHold;
}

bool Card::getIsHold() const
{
	return this->m_bIsHold;
}

void Card::setIsGood(bool isGood)
{
	this->m_isGood = isGood;
}

bool Card::getIsGood() const 
{
	return this->m_isGood;
}


void Card::setCardPosition(eCardPosition position)
{
	this->m_position = position;
}

eCardPosition Card::getCardPosition() const
{
	return this->m_position;
}



bool operator<(const Card & oldcard, const Card & newcard)
{
 	return (oldcard.getCardValue() < newcard.getCardValue());
}

bool operator==(const Card & leftValue, const Card & rightValue)
{
	return leftValue.getCardValue() ==rightValue.getCardValue() && leftValue.getCardSuit() == rightValue.getCardSuit();
}

