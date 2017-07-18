#include "EvalThreeOfKind.h"
#include <iostream>

EvalThreeOfKind::EvalThreeOfKind()
{
}

EvalThreeOfKind::~EvalThreeOfKind()
{
	std::cout << "Deleted ThreeOfKind.\n";
}

int EvalThreeOfKind::EvaluateHand(std::vector<Card>& hand)
{
	for(int i = 0; i < hand.size() - 2; i++)
	{
		if(hand[i].getCardValue() == hand[i + 1].getCardValue() &&
			hand[i + 1].getCardValue() == hand[i + 2].getCardValue())
			return 8;
	}

	for(int i = 0; i < hand.size() - 1; i++)
	{
		if(hand[i].getCardValue() == hand[i + 1].getCardValue() && HasJoker(hand) == true)
		{
			return 8;
		}
	}

		return -1;
}

bool EvalThreeOfKind::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
