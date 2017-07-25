#ifndef EVAL_STRAIGHT_FLUSH_H
#define EVAL_STRAIGHT_FLUSH_H
#include "Evaluation.h"
#include "EvalStraight.h"
#include "EvalFlush.h"

class EvalStraightFlush : public EvalStraight, public EvalFlush
{
private:
	bool hasGoodCard;
public:
	EvalStraightFlush();
	virtual~EvalStraightFlush();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>& hand);

};
#endif 

