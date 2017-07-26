#ifndef EVAL_KINGS_OR_BETTER
#define EVAL_KINGS_OR_BETTER

#include "Evaluation.h"

class EvalKingsOrBetter : public Evaluation 
{	
private:
	bool hasGoodCard;
public:
	EvalKingsOrBetter();
	virtual ~EvalKingsOrBetter();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasJoker(std::vector<Card>& hand);
	bool HasGoodCards()const;
};
#endif 
