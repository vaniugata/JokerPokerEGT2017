#include "EvalStraight.h"

EvalStraight::EvalStraight()
{
}

EvalStraight::~EvalStraight()
{
}

int EvalStraight::EvaluateHand(std::vector<Card>& hand)
{
	int count = 0;
	if(HasJoker(hand)) { count++; }
	for(int i = 0; i < hand.size() - 1; i++)
	{
		if(hand[i].getCardValue() == hand[i + 1].getCardValue() - 1)
		{
			count++;
		}

		if(HasAce(hand) && count == 3 &&
			(hand[0].getCardValue() == DEUCE || hand[0].getCardValue() == THREE) )
		{
			return 7;
		}
	}

	if(count == 4 || (count == 3 && HasJoker(hand) ) ) { return 7; }

	return -1;
}

bool EvalStraight::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}

bool EvalStraight::HasAce(std::vector<Card>& hand)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getCardValue() == ACE)
		{
			return true;
		}
	}
	return false;
}
