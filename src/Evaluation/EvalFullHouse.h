#ifndef EVAL_FULL_HOUSE_H
#define EVAL_FULL_HOUSE_H
#include "EvalThreeOfKind.h"
#include "Evaluation.h"
#include "EvalTwoPair.h"

class EvalFullHouse : public EvalThreeOfKind, public EvalTwoPair
{
private:
	bool hasGoodCard;
public:
	EvalFullHouse();
	virtual~EvalFullHouse();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasJoker(std::vector<Card>& hand);
	bool HasGoodCards()const;
};
#endif
   
