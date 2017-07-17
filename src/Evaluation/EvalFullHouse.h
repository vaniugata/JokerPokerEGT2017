#ifndef EVAL_FULL_HOUSE_H
#define EVAL_FULL_HOUSE_H
#include "EvalThreeOfKind.h"
#include "EvalTwoPair.h"

class EvalFullHouse : public Evaluation, public EvalThreeOfKind, public EvalTwoPair
{
public:
	EvalFullHouse();
	virtual~EvalFullHouse();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif

