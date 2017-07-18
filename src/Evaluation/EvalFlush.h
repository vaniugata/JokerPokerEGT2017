#ifndef EVAL_FLUSH_H
#define EVAL_FLUSH_H
#include "Evaluation.h"

class EvalFlush : public virtual Evaluation
{
public:
	EvalFlush();
	virtual~EvalFlush();

	int EvaluateHand(std::vector<Card>& hand);
	bool HasJoker(std::vector<Card>& hand);
};
#endif

