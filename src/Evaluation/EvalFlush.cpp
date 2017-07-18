#include "EvalFlush.h"

EvalFlush::EvalFlush()
{

}

EvalFlush::~EvalFlush()
{

}

int EvalFlush::EvaluateHand(std::vector<Card>& hand)
{
	int count = 0;

	for(int i = 0; i < hand.size() - 1; i++)
	{
		if(hand[i].getCardSuit() == hand[i + 1].getCardSuit())
		{
			count++;
		}
	}

	if(HasJoker(hand)) { count++; }

	if(count == 4) { return 6; }

	return -1;
}

bool EvalFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
