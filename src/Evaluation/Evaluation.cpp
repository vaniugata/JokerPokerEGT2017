#include "Evaluation.h"
#include <iostream>


Evaluation::Evaluation()
{
	
}

Evaluation::~Evaluation()
{
	std::cout << "Delete Evaluation.\n";
}

std::vector<Card> Evaluation::EvaluateHand(std::vector<Card> hand)
{
	return std::vector<Card>();
}

bool Evaluation::HasJoker(std::vector<Card>& hand)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getCardValue() == JOKERVALUE) 
		{ 
			hand[i].setIsGood(true);
			return true; 
		}
	}
	return false;
}
