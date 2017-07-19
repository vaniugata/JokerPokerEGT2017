#include "EvalTwoPair.h"

EvalTwoPair::EvalTwoPair()
{
}

EvalTwoPair::~EvalTwoPair()
{
}

int EvalTwoPair::EvaluateHand(std::vector<Card>& hand)
{
	int pair = 0;

	for(int i = 0; i < hand.size() - 1; i++)
	{
		if (hand[i].getCardValue() == hand[i + 1].getCardValue()) { pair++; i++; }
	}

	if(pair == 2 && HasJoker(hand) == false) {	return 9; }

	return -1;
}

bool EvalTwoPair::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
