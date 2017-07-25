#ifndef  EVAL_FOUR_OF_A_KIND_H
#define EVAL_FOUR_OF_A_KIND_H
#include "Evaluation.h"

class EvalFourOfAKind : public virtual Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalFourOfAKind();
	virtual~EvalFourOfAKind();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>& hand);
	eCardValue getBestValue(vector<Card>);

};
#endif

