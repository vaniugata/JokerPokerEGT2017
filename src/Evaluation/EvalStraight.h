#ifndef EVAL_STRAIGHT_H
#define EVAL_STRAIGHT_H
#include "Evaluation.h"

class EvalStraight : public Evaluation
{
public:
	EvalStraight();
	virtual~EvalStraight();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
	bool HasAce(std::vector<Card>& hand);
};
#endif 

