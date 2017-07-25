#ifndef EVAL_JOKER_ONLY
#define EVAL_JOKER_ONLY
#include "Evaluation.h"

class EvalJokerOnly :public Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalJokerOnly();
	~EvalJokerOnly();

	std::vector<Card> EvaluateHand(std::vector<Card>);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>&);
};
#endif
