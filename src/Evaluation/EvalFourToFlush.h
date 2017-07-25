#ifndef EVAL_FOUR_TO_FLUSH
#define EVAL_FOUR_TO_FLUSH
#include "Evaluation.h"

class EvalFourToFlush : public Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalFourToFlush();
	~EvalFourToFlush();

	std::vector<Card> EvaluateHand(std::vector<Card>);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>&);
	eCardSuit getBestSuit(std::vector<Card> hand);
};
#endif
