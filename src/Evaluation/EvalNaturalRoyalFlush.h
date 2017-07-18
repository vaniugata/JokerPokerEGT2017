#ifndef EVAL_NATURAL_ROYAL_FLUSH_H
#define EVAL_NATURAL_ROYAL_FLUSH_H
#include "EvalStraightFlush.h"

class EvalNaturalRoyalFlush : public Evaluation, public EvalStraightFlush
{
public:
	EvalNaturalRoyalFlush();
	virtual~EvalNaturalRoyalFlush();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif
