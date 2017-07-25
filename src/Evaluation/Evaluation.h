#ifndef EVALUATION_H
#define EVALUATION_H

#include "../Deck.h"
#include <vector>
using std::vector;

class Evaluation
{

private:
	static bool isAutoHold;
public:
	Evaluation();
	virtual~Evaluation();	
	virtual bool HasGoodCards()const = 0;
	static void setAutoHold(bool);
	static bool getAutoHold();

	virtual std::vector<Card> EvaluateHand(std::vector<Card> hand) = 0;
	virtual bool HasJoker(std::vector<Card>& hand);
};
#endif
