#include "EvalThreeOfKind.h"
#include <iostream>

EvalThreeOfKind::EvalThreeOfKind()
{
	this->hasGoodCard = false;
}

EvalThreeOfKind::~EvalThreeOfKind()
{
	std::cout << "Deleted ThreeOfKind.\n";
}

std::vector<Card> EvalThreeOfKind::EvaluateHand(std::vector<Card> hand)
{

	if (HasJoker(hand))
	{
		for (int i = 0; i < hand.size() - 1; i++)
		{
			if (hand[i].getCardValue() == hand[i + 1].getCardValue())
			{
				hand[i].setIsGood(true);
				hand[i + 1].setIsGood(true);
				this->hasGoodCard = true;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < hand.size() - 2; i++)
		{
			if (hand[i].getCardValue() == hand[i + 1].getCardValue()
				&& hand[i].getCardValue() == hand[i + 2].getCardValue())
			{
				hand[i].setIsGood(true);
				hand[i + 1].setIsGood(true);
				hand[i + 2].setIsGood(true);
			this->hasGoodCard = true;
			}
		}
	}

	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
}

bool EvalThreeOfKind::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool EvalThreeOfKind::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
