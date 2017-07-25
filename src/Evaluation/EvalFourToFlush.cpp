
#include "EvalFourToFlush.h"
#include<iostream>

EvalFourToFlush::EvalFourToFlush()
{
	this->hasGoodCard = false;
}

EvalFourToFlush::~EvalFourToFlush()
{
	std::cout << "FourToFlush deleted/n";
}

std::vector<Card> EvalFourToFlush::EvaluateHand(std::vector<Card> hand)
{
	eCardSuit bestSuit = getBestSuit(hand);
	int counter = 0;
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardSuit() < right.getCardSuit();
	});
	for (int i = 0; i < hand.size()-1; i++)
	{
		if (hand[i].getCardSuit() == hand[i+1].getCardSuit() &&hand[i].getCardSuit()==bestSuit)
		{
			counter++;
		}
	}
	if (counter==3 
		|| (counter == 2 && HasJoker(hand)))
	{
		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i].getCardSuit() == bestSuit)
			{
				hand[i].setIsGood(true);
			}
		}
		HasJoker(hand);
		this->hasGoodCard = true;
	}
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
	
}

bool EvalFourToFlush::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool EvalFourToFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

eCardSuit EvalFourToFlush::getBestSuit(std::vector<Card> hand)
{
	eCardSuit bestSuit = EMPTYSUIT;
	int counter = 0;
	int best = 0;
	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = i + 1; j < hand.size(); j++)
		{
			if (hand[i].getCardSuit() == hand[j].getCardSuit())
			{
				counter++;
			}
		}
		if (counter > best)
		{
			best = counter;
			bestSuit = hand[i].getCardSuit();
		}
		counter = 0;
	}

	return bestSuit;
}


