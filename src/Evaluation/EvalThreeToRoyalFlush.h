#ifndef EVAL_THREE_TO_ROYAL_FLUSH
#define EVAL_THREE_TO_ROYAL_FLUSH
#include "Evaluation.h"

class EvalThreeToRoyalFlush : public Evaluation
{
private: 
	bool hasGoodCard;
public:
	EvalThreeToRoyalFlush();
	~EvalThreeToRoyalFlush();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasJoker(std::vector<Card>& hand);
	bool HasGoodCards()const;

	eCardSuit getbestSuit(std::vector<Card>);
	std::vector<Card> getRoyalFlushHand(eCardSuit);
};
#endif 

