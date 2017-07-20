#ifndef EVAL_TWO_PAIR_H
#define EVAL_TWO_PAIR_H
#include "Evaluation.h"

class EvalTwoPair : public virtual Evaluation
{
public:
	EvalTwoPair();
	virtual~EvalTwoPair();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif
