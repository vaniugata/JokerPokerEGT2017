#ifndef EVAL_FOUR_TO_ROYAL_FLUSH
#define EVAL_FOUR_TO_ROYAL_FLUSH
#include "Evaluation.h"

class EvalFourToRoyalFlush : public Evaluation
{
private:
	bool hasGoodCard;
public:
	EvalFourToRoyalFlush();
	~EvalFourToRoyalFlush();

	std::vector<Card> EvaluateHand(std::vector<Card> hand);
	bool HasJoker(std::vector<Card>& hand);
	bool HasGoodCards()const;

	eCardSuit getbestSuit(std::vector<Card>);
	std::vector<Card> getRoyalFlushHand(eCardSuit);
};
#endif
