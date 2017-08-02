#include "EvalStraightFlush.h"
#include<iostream>

EvalStraightFlush::EvalStraightFlush()
	:hasGoodCard(false)
{
}

EvalStraightFlush::~EvalStraightFlush()
{
	std::cout << "StraightFlush delete/n";
}

std::vector<Card> EvalStraightFlush::EvaluateHand(std::vector<Card> hand)
{
	this->hasGoodCard = false;
	EvalFlush::EvaluateHand(hand);
	EvalStraight::EvaluateHand(hand);
	if (EvalFlush::HasGoodCards()==true && EvalStraight::HasGoodCards()==true)
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

bool EvalStraightFlush::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool EvalStraightFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
