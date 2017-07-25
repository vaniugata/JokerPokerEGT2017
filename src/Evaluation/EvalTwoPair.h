#ifndef EVAL_TWO_PAIR_H
#define EVAL_TWO_PAIR_H
#include "Evaluation.h"

class EvalTwoPair : public virtual Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalTwoPair();
	virtual~EvalTwoPair();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasJoker(std::vector<Card>& hand);
	bool HasGoodCards()const;
};
#endif
