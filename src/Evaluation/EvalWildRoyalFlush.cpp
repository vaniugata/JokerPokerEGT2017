#include "EvalWildRoyalFlush.h"
#include <iostream>

EvalWildRoyalFlush::EvalWildRoyalFlush()
	:hasGoodCard(false)
{
}

EvalWildRoyalFlush::~EvalWildRoyalFlush()
{
	std::cout << "WildRoyalFlush deleted/n";
}

std::vector<Card> EvalWildRoyalFlush::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	EvalStraightFlush::EvaluateHand(hand);
	if (EvalStraightFlush::HasGoodCards() == true && hand[0].getCardValue() == TEN && HasJoker(hand))
	{
		for (int i = 0; i < hand.size(); i++)
		{
			hand[i].setIsGood(true);
		}
		this->hasGoodCard = true;
	}
	sort(hand.begin(), hand.end(), [](const Card& left, const Card& right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
}

bool EvalWildRoyalFlush::HasGoodCards()
{
	return this->hasGoodCard;
}

bool EvalWildRoyalFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand); 
}
