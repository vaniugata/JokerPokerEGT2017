#include "EvalFiveOfAKind.h"
#include<iostream>

EvalFiveOfAKind::EvalFiveOfAKind()
	:hasGoodCard(false)
{
}

EvalFiveOfAKind::~EvalFiveOfAKind()
{
	std::cout << "FiveOfAkind deleted/n";
}

std::vector<Card> EvalFiveOfAKind::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	int counter = 0;
	for (int i = 0; i < hand.size()-1; i++)
	{
		if (hand[i].getCardValue() == hand[i + 1].getCardValue())
		{
			counter++;
		}
	}
	if (counter == 3 && HasJoker(hand))
	{
		for (int i = 0; i < hand.size() - 1; i++)
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

bool EvalFiveOfAKind::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool EvalFiveOfAKind::HasGoodCards()const
{
	return this->hasGoodCard;
}
