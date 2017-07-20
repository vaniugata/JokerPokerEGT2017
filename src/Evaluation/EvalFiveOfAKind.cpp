#include "EvalFiveOfAKind.h"

EvalFiveOfAKind::EvalFiveOfAKind()
{
}

EvalFiveOfAKind::~EvalFiveOfAKind()
{
}

int EvalFiveOfAKind::EvaluateHand(std::vector<Card>& hand)
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

	if(count == 4) { return 1; }

	return -1;
}

bool EvalFiveOfAKind::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
