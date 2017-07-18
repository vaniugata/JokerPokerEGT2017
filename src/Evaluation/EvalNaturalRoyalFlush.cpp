#include "EvalNaturalRoyalFlush.h"

EvalNaturalRoyalFlush::EvalNaturalRoyalFlush()
{
}

EvalNaturalRoyalFlush::~EvalNaturalRoyalFlush()
{
}

int EvalNaturalRoyalFlush::EvaluateHand(std::vector<Card>& hand)
{
	if(EvalStraightFlush::EvaluateHand(hand) == 3 &&
		hand[0].getCardValue() == TEN &&
		!HasJoker(hand))
	{
		return 0;
	}

	return -1;
}

bool EvalNaturalRoyalFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
