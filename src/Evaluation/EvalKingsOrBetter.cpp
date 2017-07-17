#include "EvalKingsOrBetter.h"

EvalKingsOrBetter::EvalKingsOrBetter()
{
}

EvalKingsOrBetter::~EvalKingsOrBetter()
{
}

int EvalKingsOrBetter::EvaluateHand(std::vector<Card>& hand)
{
	int iKingCount = 0, iAceCout = 0;
	bool hasJoker = false;
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getCardValue() == KING) { iKingCount++; }
		 if(hand[i].getCardValue() == ACE) { iAceCout++; }
		if(hand[i].getCardValue() == JOKERVALUE) { hasJoker = true; }
	}

	if(iAceCout == 2 || iKingCount == 2) { return 10;}
	else if(iKingCount == 1 && hasJoker || iAceCout == 1 && hasJoker) {	return 10;}

	return -1; 
}

bool EvalKingsOrBetter::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
