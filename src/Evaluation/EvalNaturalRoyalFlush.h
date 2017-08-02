#ifndef EVAL_NATURAL_ROYAL_FLUSH_H
#define EVAL_NATURAL_ROYAL_FLUSH_H
#include "EvalStraightFlush.h"

class EvalNaturalRoyalFlush : public Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalNaturalRoyalFlush();
	virtual~EvalNaturalRoyalFlush();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>& hand);
};
#endif
