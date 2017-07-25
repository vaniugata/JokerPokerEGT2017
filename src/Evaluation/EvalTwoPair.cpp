#include "EvalTwoPair.h"
#include<iostream>

EvalTwoPair::EvalTwoPair()
	:hasGoodCard(false)
{
}

EvalTwoPair::~EvalTwoPair()
{
	std::cout << "TwoPair deleted/n";
}


std::vector<Card> EvalTwoPair::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	int pair = 0;
	if (!HasJoker(hand))
	{
		for (int i = 0; i < hand.size() - 1; i++)
		{
			if (hand[i].getCardValue() == hand[i + 1].getCardValue())
			{
				pair++;
				i++;
			}
		}
	}
	if (pair == 2)
	{
		this->hasGoodCard = true;
		for (int i = 0; i < hand.size() - 1; i++)
		{
			if (hand[i].getCardValue() == hand[i + 1].getCardValue())
			{
				hand[i].setIsGood(true);
				hand[i + 1].setIsGood(true);
				i++;
			}
		}
	}
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
}

bool EvalTwoPair::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool EvalTwoPair::HasGoodCards() const
{
	return this->hasGoodCard;
}


