#ifndef EVAL_FLUSH_H
#define EVAL_FLUSH_H
#include "Evaluation.h"

class EvalFlush : public virtual Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalFlush();
	virtual~EvalFlush();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>& hand);
};
#endif

