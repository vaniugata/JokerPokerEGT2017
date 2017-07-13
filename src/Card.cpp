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
	}
	return *this;
}

Card::Card()
{
	this->m_cardSuit = EMPTYSUIT;
	this->m_cardValue = EMPTYVALUE;
	m_bIsHold = false;
}

Card::Card(eCardSuit cardSuit,eCardValue cardValue,SDL_Rect rect)
{
	    this->m_cardSuit = cardSuit;
		this->m_cardValue = cardValue;
		this->m_cardRect = rect;
		

}





eCardSuit Card::getCardSuit()const
{
	return this->m_cardSuit;
}

eCardValue Card::getCardValue()const
{
	return this->m_cardValue;
}

SDL_Rect Card::getCardRect()
{
	return this->m_cardRect;
}

void Card::setCardSuit(eCardSuit suit)
{
	this->m_cardSuit = suit;
}

void Card::setCardValue(eCardValue value)
{
	this->m_cardValue = value;
}

void Card::setCardRect(SDL_Rect rect)
{
	this->m_cardRect = rect;
}

void Card::setIsHold(bool isHold)
{
	this->m_bIsHold = isHold;
}

bool Card::getIsHold()
{
	return this->m_bIsHold;
}

bool operator<(const Card & oldcard, const Card & newcard)
{
 	return (oldcard.getCardValue() < newcard.getCardValue());
}

bool operator==(const Card & leftValue, const Card & rightValue)
{
	return leftValue.getCardValue() ==rightValue.getCardValue() && leftValue.getCardSuit() == rightValue.getCardSuit();
}

//bool operator==(eCardValue leftValue, eCardValue rightValue)
//{
//	return (int) leftValue == (int) rightValue;
//}
