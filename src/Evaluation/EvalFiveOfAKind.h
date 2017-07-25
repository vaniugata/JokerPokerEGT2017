#ifndef EVAL_FIVE_OF_A_KIND
#define EVAL_FIVE_OF_A_KIND
#include "EvalFourOfAKind.h"

class EvalFiveOfAKind : public Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalFiveOfAKind();
	virtual~EvalFiveOfAKind();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasJoker(std::vector<Card>& hand);
	bool HasGoodCards()const;
};
#endif