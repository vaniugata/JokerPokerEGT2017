#include "EvalFourOfAKind.h"

EvalFourOfAKind::EvalFourOfAKind()
{
}

EvalFourOfAKind::~EvalFourOfAKind()
{
}

int EvalFourOfAKind::EvaluateHand(std::vector<Card>& hand)
{
	int count = 0;

	if(HasJoker(hand)) { count++; }
	for(int i = 0; i < hand.size() - 1; i++)
	{
		if(hand[i].getCardValue() == hand[i + 1].getCardValue())
		{
			count++;
		}
	}

	if(count == 3) { return 4; }

	return -1;
}

bool EvalFourOfAKind::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
