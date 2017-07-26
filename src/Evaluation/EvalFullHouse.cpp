#include "EvalFullHouse.h"
#include<iostream>
EvalFullHouse::EvalFullHouse()
	:hasGoodCard(false)
{
}

EvalFullHouse::~EvalFullHouse()
{
	std::cout << "FullHouse deleted/n";
}

std::vector<Card> EvalFullHouse::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	bool isFull =false;
	if (EvalThreeOfKind::HasGoodCards()==true)
	{
		if (hand[0].getCardValue() == hand[2].getCardValue())
		{
			if(hand[3].getCardValue()==hand[4].getCardValue())
			{
				isFull = true;
			}
		}
		else if(hand[2].getCardValue() == hand[4].getCardValue())
		{
			if (hand[0].getCardValue() == hand[1].getCardValue())
			{
				isFull = true;
			}
		}
				
    }
	else if(EvalTwoPair::HasGoodCards() && HasJoker(hand))
	{
		isFull = true;
	}
	if (isFull)
	{
		for (int i = 0; i < hand.size(); i++)
		{
			hand[i].setIsGood(true);
		}
		this->hasGoodCard = true;
	}
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
}

bool EvalFullHouse::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool EvalFullHouse::HasGoodCards()const
{
	return this->hasGoodCard;
}

