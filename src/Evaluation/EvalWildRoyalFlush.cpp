#include "EvalWildRoyalFlush.h"

EvalWildRoyalFlush::EvalWildRoyalFlush()
{

}

EvalWildRoyalFlush::~EvalWildRoyalFlush()
{
}

int EvalWildRoyalFlush::EvaluateHand(std::vector<Card>& hand)
{
	if(EvalStraightFlush::EvaluateHand(hand) == 3 && HasJoker(hand) && 
		hand[0].getCardValue() == TEN || hand[0].getCardValue() == JACK)
	{
		return 2;
	}

	return -1;
}

bool EvalWildRoyalFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}


