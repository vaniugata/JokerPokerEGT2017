#include "EvalJokerOnly.h"
#include<iostream>

EvalJokerOnly::EvalJokerOnly()
	:hasGoodCard(false)
{
}

EvalJokerOnly::~EvalJokerOnly()
{
	std::cout << "JokerOnly deleted/n";
}

std::vector<Card> EvalJokerOnly::EvaluateHand(std::vector<Card>hand)
{
	this->hasGoodCard = false;
	if (HasJoker(hand))
	{
		this->hasGoodCard = true;
	}
		sort(hand.begin(), hand.end(), [](const Card left, const Card right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	return hand;
}

bool EvalJokerOnly::HasGoodCards()const
{
	return this->hasGoodCard;
}

bool EvalJokerOnly::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
