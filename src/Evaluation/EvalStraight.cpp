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
	if (HasAce(hand) && HasJoker(hand)) { count--; }
	for(int i = 0; i < hand.size() - 1; i++)
	{
		if(hand[i].getCardValue() == hand[i + 1].getCardValue() - 1)
		{
			count++;
		}
		//checks for 2 3 4 5 A
		if(HasAce(hand) && count == 3 &&
			hand[3].getCardValue() == FIVE )
		{
			return 7;
		}
		//checks for 2 3 5 A Jok
		if (count == 2 && HasAce(hand) && hand[2].getCardValue() <= FIVE && hand[3].getCardValue() == ACE) { return 7; }
	}
	if (HasAce(hand) && HasJoker(hand)) { count--; }
	if(count == 4 || (count == 3 && HasJoker(hand) && hand[0].getCardValue()==hand[3].getCardValue()-2 ) ) { return 7; }

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
