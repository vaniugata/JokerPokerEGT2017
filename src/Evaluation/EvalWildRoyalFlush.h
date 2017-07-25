#ifndef EVAL_WILD_ROYAL_FLUSH
#define EVAL_WILD_ROYAL_FLUSH
#include "EvalStraightFlush.h"

class EvalWildRoyalFlush : public EvalStraightFlush
{
private:
	bool hasGoodCard;
public:
	EvalWildRoyalFlush();
	virtual~EvalWildRoyalFlush();

    std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasGoodCards();
	bool HasJoker(std::vector<Card>& hand);
};
#endif
