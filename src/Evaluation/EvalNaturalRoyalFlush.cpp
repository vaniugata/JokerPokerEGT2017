#include "EvalNaturalRoyalFlush.h"
#include <iostream>

EvalNaturalRoyalFlush::EvalNaturalRoyalFlush()
	:hasGoodCard(false)
{
}

EvalNaturalRoyalFlush::~EvalNaturalRoyalFlush()
{
	std::cout << "NaturalRoyalFlush deleted/n";
}

std::vector<Card> EvalNaturalRoyalFlush::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	if (EvalStraightFlush::HasGoodCards()==true && hand[0].getCardValue() == TEN && !HasJoker(hand))
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

bool EvalNaturalRoyalFlush::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool EvalNaturalRoyalFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
