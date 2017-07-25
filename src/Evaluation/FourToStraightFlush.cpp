#include "FourToStraightFlush.h"
#include<iostream>
FourToStraightFlush::FourToStraightFlush()
	:hasGoodCard(false)
{
}

FourToStraightFlush::~FourToStraightFlush()
{
	std::cout << "FourToStraightFlush deletet/n";
}

std::vector<Card> FourToStraightFlush::EvaluateHand(std::vector<Card>hand)
{
	this->hasGoodCard = false;
	eCardSuit bestsuit = getBestSuit(hand);
	std::vector<Card> straightFlush;
	if (hand[0].getCardValue() == hand[1].getCardValue() - 1) {
	    straightFlush = getStraightFlush(hand[0].getCardValue(), bestsuit);
	}
	else if(HasJoker(hand) && hand[0].getCardValue() == hand[1].getCardValue() - 2)
	{
		straightFlush = getStraightFlush(hand[1].getCardValue(), bestsuit);
	}
	else
	{
	    straightFlush = getStraightFlush(hand[1].getCardValue(), bestsuit);
	}
	int counter = 0;
	for (int i = 0; i < hand.size(); i++)
	{
		for  (int j=0; j < hand.size(); j++)
		{
			if (hand[i] == straightFlush[j])
			{
				counter++;
			}
		}
	}
	if (counter >= 4
		|| counter == 3 && HasJoker(hand)
		|| counter == 3 && HasAce(hand) && straightFlush[0].getCardValue()<=FOUR
		|| counter == 2 && HasAce(hand) && HasJoker(hand) && straightFlush[0].getCardValue() <= FOUR)
	{
		for (int i = 0; i < hand.size(); i++)
		{
			for (int j = 0; j < hand.size(); j++)
			{
				if (hand[i] == straightFlush[j])
				{
					hand[i].setIsGood(true);
					break;
				}
			}
		}
		this->hasGoodCard = true;
	}
	sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;

}

bool FourToStraightFlush::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool FourToStraightFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool FourToStraightFlush::HasAce(std::vector<Card>& hand)
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].getCardValue() == ACE && hand[i].getCardSuit() == getBestSuit(hand))
		{
			hand[i].setIsGood(true);
			return true;
		}
	}
	return false;
}

eCardSuit FourToStraightFlush::getBestSuit(std::vector<Card> hand)
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

std::vector<Card> FourToStraightFlush::getStraightFlush(eCardValue value, eCardSuit suit)
{
	vector<Card> straightFlush;
	Card currentCard;
	for (int i = 0; i < 5; i++)
	{
		currentCard.setCardValue(static_cast<eCardValue>(value + i));
		currentCard.setCardSuit(suit);
		straightFlush.push_back(currentCard);
	}
	return straightFlush;
}
