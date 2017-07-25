#include "EvalFourToRoyalFlush.h"
#include<iostream>
EvalFourToRoyalFlush::EvalFourToRoyalFlush()
{
	this->hasGoodCard = false;
}

EvalFourToRoyalFlush::~EvalFourToRoyalFlush()
{
	std::cout << "FourToRoyal deleted/n";
}

std::vector<Card> EvalFourToRoyalFlush::EvaluateHand(std::vector<Card> hand)
{
	int counter = 0;
	std::vector<Card> royalFlush = getRoyalFlushHand(getbestSuit(hand));

	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = 0; j < hand.size(); j++)
		{
			if (hand[i] == royalFlush[j])
			{
				counter++;
			}
		}
		if (counter == 4) { break; }
	}
	if (counter == 4
		|| counter == 3 && HasJoker(hand))
	{
		for (int i = 0; i < hand.size(); i++)
		{
			for (int j = 0; j < hand.size(); j++)
			{
				if (hand[i] == royalFlush[j])
				{
					hand[i].setIsGood(true);
				}
			}

		}
		HasJoker(hand);
		hasGoodCard = true;
	}
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
	
}

bool EvalFourToRoyalFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool EvalFourToRoyalFlush::HasGoodCards()const
{
	return this->hasGoodCard;
}

eCardSuit EvalFourToRoyalFlush::getbestSuit(std::vector<Card> hand)
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

std::vector<Card> EvalFourToRoyalFlush::getRoyalFlushHand(eCardSuit suit)
{

	std::vector<Card> royal;
	Card currentCard;
	for (int i = 0; i < 5; i++)
	{

		currentCard.setCardValue(static_cast<eCardValue>(i + 9));
		currentCard.setCardSuit(suit);
		royal.push_back(currentCard);
	}
	return royal;
}
