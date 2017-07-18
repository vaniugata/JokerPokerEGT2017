#ifndef EVAL_STRAIGHT_FLUSH_H
#define EVAL_STRAIGHT_FLUSH_H
#include "Evaluation.h"
#include "EvalStraight.h"
#include "EvalFlush.h"

class EvalStraightFlush :  public EvalStraight, public EvalFlush
{
public:
	EvalStraightFlush();
	virtual~EvalStraightFlush();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);

};
#endif 

