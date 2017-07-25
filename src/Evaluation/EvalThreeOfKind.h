#ifndef EVAL_THREE_OF_KIND
#define EVAL_THREE_OF_KIND
#include "Evaluation.h"

class EvalThreeOfKind : public virtual Evaluation
{
private :
	bool hasGoodCard;
public:
	EvalThreeOfKind();
	virtual~EvalThreeOfKind();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>& hand);
};
#endif
