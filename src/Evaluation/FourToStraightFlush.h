#ifndef FOUR_TO_FLUSH
#define FOUR_TO_FLUSH
#include "Evaluation.h"
#include "EvalThreeToRoyalFlush.h"

class FourToStraightFlush : public Evaluation
{
private:
	bool hasGoodCard;
public:
	FourToStraightFlush();
	~FourToStraightFlush();

	std::vector<Card> EvaluateHand(std::vector<Card>);
	bool HasGoodCards()const;
	bool HasJoker(std::vector<Card>&);
	bool HasAce(std::vector<Card>& hand);

	eCardSuit getBestSuit(std::vector<Card>);
	std::vector<Card> getStraightFlush(eCardValue, eCardSuit);

};
#endif