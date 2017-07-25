#include "EvalKingsOrBetter.h"
#include<iostream>


EvalKingsOrBetter::EvalKingsOrBetter()
	:hasGoodCard(false)
{
}

EvalKingsOrBetter::~EvalKingsOrBetter()
{
	std::cout << "KingsOrbetter deleted/n";
}

std::vector<Card> EvalKingsOrBetter::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	if (HasJoker(hand))
	{
		if (hand[3].getCardValue() >= KING)
		{
			hand[3].setIsGood(true);
			this->hasGoodCard = true;
		}
	}
	else if (hand[3].getCardValue() == hand[4].getCardValue() && hand[3].getCardValue() >= KING)
		{
			hand[3].setIsGood(true);
			hand[4].setIsGood(true);
			this->hasGoodCard = true;
		}
	else if (hand[2].getCardValue() == hand[3].getCardValue() && hand[3].getCardValue() >= KING)
	{
		hand[3].setIsGood(true);
		hand[4].setIsGood(true);
		this->hasGoodCard = true;
	}

		
	
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});

	return hand;

}

bool EvalKingsOrBetter::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool EvalKingsOrBetter::HasGoodCards()const
{
	return this->hasGoodCard;
}
