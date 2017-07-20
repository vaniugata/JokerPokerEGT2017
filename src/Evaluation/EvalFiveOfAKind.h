#ifndef EVAL_FIVE_OF_A_KIND
#define EVAL_FIVE_OF_A_KIND
#include "EvalFourOfAKind.h"

class EvalFiveOfAKind : public Evaluation
{
public: 
	EvalFiveOfAKind();
	virtual~EvalFiveOfAKind();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif