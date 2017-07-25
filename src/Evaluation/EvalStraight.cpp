#include "EvalStraight.h"
#include<iostream>
EvalStraight::EvalStraight()
{
	this->hasGoodCard = false;
}

EvalStraight::~EvalStraight()
{
	std::cout << "Deleted Straight/n";
}



std::vector<Card> EvalStraight::EvaluateHand(std::vector<Card> hand)
{
	std::vector<Card> straight = getStraight(hand[0].getCardValue());
	int counter=0;
	
	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = 0; j <hand.size(); j++)
		{
			if (hand[i].getCardValue() == straight[j].getCardValue())
			{
				counter++;
				straight[j].setCardValue(EMPTYVALUE);
				break;
			}
		}
	}
	straight = getStraight(hand[0].getCardValue());
	
	if (counter == 5 
		||( counter == 4 && HasJoker(hand) )
		||( counter == 4 && HasAce(hand) && hand[3].getCardValue() <= FIVE)
		|| (counter==3 && HasAce(hand) && hand[2].getCardValue() <= FIVE &&  HasJoker(hand)))
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

bool EvalStraight::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool EvalStraight::HasGoodCards()const
{
	return this->hasGoodCard;
}

std::vector<Card> EvalStraight::getStraight(eCardValue value)
{
	std::vector<Card> straight;
	Card currentCard;
	for (int i = 0; i < 5; i++)
	{
		currentCard.setCardValue(static_cast<eCardValue>(value + i));
		straight.push_back(currentCard);
	}
	return straight;
}

bool EvalStraight::HasAce(std::vector<Card>& hand)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getCardValue() == ACE)
		{
			return true;
		}
	}
	return false;
}
