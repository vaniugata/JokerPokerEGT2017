#include "EvalFullHouse.h"

EvalFullHouse::EvalFullHouse()
{
}

EvalFullHouse::~EvalFullHouse()
{
}

int EvalFullHouse::EvaluateHand(std::vector<Card>& hand)
{
	if(EvalThreeOfKind::EvaluateHand(hand) == 8)
	{
		if(hand[0].getCardValue() == hand[1].getCardValue() ||
			hand[3].getCardValue() == hand[4].getCardValue())
		{
			return 5;
		}
	}

	else if(EvalTwoPair::EvaluateHand(hand) == 9 && HasJoker(hand))
	{
		return 5;
	}

	return -1;
}

bool EvalFullHouse::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
