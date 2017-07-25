#include "EvalFourOfAKind.h"
#include<iostream>

EvalFourOfAKind::EvalFourOfAKind()
	:hasGoodCard(false)
{
}

EvalFourOfAKind::~EvalFourOfAKind()
{
	std::cout << "FourOfAking deleted/n";
}

std::vector<Card> EvalFourOfAKind::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	int counter = 0;
	eCardValue bestValue = getBestValue(hand);
	for (int i = 0; i < hand.size()-1; i++)
	{
		if (hand[i].getCardValue() == hand[i + 1].getCardValue() && hand[i].getCardValue()==bestValue)
		{
			counter++;
		}
	}
	if (counter == 3
		|| counter == 2 && HasJoker(hand))
	{
		for  (int i = 0; i < hand.size(); i++)
		{
			if (hand[i].getCardValue() == bestValue)
			{
				hand[i].setIsGood(true);
			}
			this->hasGoodCard = true;
		}
	}
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
}

bool EvalFourOfAKind::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool EvalFourOfAKind::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

eCardValue EvalFourOfAKind::getBestValue(vector<Card> hand)
{
	eCardValue bestValue = EMPTYVALUE;
	int counter = 0;
	int best = 0;
	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = i + 1; j < hand.size(); j++)
		{
			if (hand[i].getCardValue() == hand[j].getCardValue())
			{
				counter++;
			}
		}
		if (counter > best)
		{
			best = counter;
			bestValue = hand[i].getCardValue();
		}
		counter = 0;
	}

	return bestValue;
}
