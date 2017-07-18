#include "EvalStraightFlush.h"

EvalStraightFlush::EvalStraightFlush()
{
}

EvalStraightFlush::
~EvalStraightFlush()
{
}

int EvalStraightFlush::EvaluateHand(std::vector<Card>& hand)
{
	if(EvalStraight::EvaluateHand(hand) == 7)
	{
		if(EvalFlush::EvaluateHand(hand) == 6)
		{
			std::cout << EvalStraight::EvaluateHand(hand) << EvalFlush::EvaluateHand(hand) << "\n";
			return 3;
		}
		
	}

	return -1;
}

bool EvalStraightFlush::HasJoker(std::vector<Card>& hand)
{
	return Evaluation::HasJoker(hand);
}
