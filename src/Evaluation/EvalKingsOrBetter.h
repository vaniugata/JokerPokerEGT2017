#ifndef EVAL_KINGS_OR_BETTER
#define EVAL_KINGS_OR_BETTER

#include "Evaluation.h"

class EvalKingsOrBetter : public Evaluation 
{
public:
	EvalKingsOrBetter();
	virtual ~EvalKingsOrBetter();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif 
