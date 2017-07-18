#ifndef EVAL_THREE_OF_KIND
#define EVAL_THREE_OF_KIND
#include "Evaluation.h"

class EvalThreeOfKind : public Evaluation
{
public:
	EvalThreeOfKind();
	virtual~EvalThreeOfKind();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif