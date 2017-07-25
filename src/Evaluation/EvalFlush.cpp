#include "EvalFlush.h"
#include<iostream>
EvalFlush::EvalFlush()
{
	this->hasGoodCard = false;
}

EvalFlush::~EvalFlush()
{
	std::cout << "Flush deleted/n";
}


std::vector<Card> EvalFlush::EvaluateHand(std::vector<Card> hand)
{
	int count = 0;
	eCardSuit bestSuit = hand[0].getCardSuit();
	for(int i = 0; i < hand.size() - 1; i++)
	{
		if(hand[i].getCardSuit() == hand[i + 1].getCardSuit() && hand[i].getCardSuit()==bestSuit)
		{
			count++;
		}
	}
	if (count == 4 || (count == 3 && HasJoker(hand)))
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

bool EvalFlush::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool EvalFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
