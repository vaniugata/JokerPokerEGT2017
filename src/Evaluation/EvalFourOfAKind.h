#ifndef  EVAL_FOUR_OF_A_KIND_H
#define EVAL_FOUR_OF_A_KIND_H
#include "Evaluation.h"

class EvalFourOfAKind : public Evaluation
{
public:
	EvalFourOfAKind();
	virtual~EvalFourOfAKind();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif

