#ifndef EVAL_WILD_ROYAL_FLUSH
#define EVAL_WILD_ROYAL_FLUSH
#include "EvalStraightFlush.h"

class EvalWildRoyalFlush : public EvalStraightFlush
{
public:
	EvalWildRoyalFlush();
	virtual~EvalWildRoyalFlush();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif