#ifndef EVAL_STRAIGHT_H
#define EVAL_STRAIGHT_H
#include "Evaluation.h"

class EvalStraight : public virtual Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalStraight();
	virtual~EvalStraight();

	std::vector<Card> EvaluateHand(std::vector<Card>);
	bool HasJoker(std::vector<Card>& hand);
	bool HasGoodCards()const;
	std::vector<Card> getStraight(eCardValue);
	bool HasAce(std::vector<Card>& hand);

};
#endif 

