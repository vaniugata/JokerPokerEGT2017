#ifndef EVALUATION_H
#define EVALUATION_H

#include "../Deck.h"
#include <vector>
using std::vector;

class Evaluation
{
public:
	Evaluation();
	virtual~Evaluation();

	virtual int EvaluateHand(std::vector<Card>& hand) = 0;
	virtual bool HasJoker(std::vector<Card>& hand);
};
#endif
