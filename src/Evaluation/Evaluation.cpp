#include "Evaluation.h"
#include <iostream>

Evaluation::Evaluation()
{
}

Evaluation::~Evaluation()
{
	std::cout << "Delete Evaluation.\n";
}

bool Evaluation::HasJoker(std::vector<Card>& hand)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getCardValue() == JOKERVALUE) { return true; }
	}
	return false;
}
