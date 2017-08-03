#ifndef RECOVERY_H
#define RECOVERY_H
#include "pugixml.hpp"
#include "Card.h"
#include <vector>
using std::vector;
struct Recover
{
	double credit;
	int bet;
	double win;
	std::vector<Card> hand;
};

class Recovery
{
public:
	Recovery();
	~Recovery();

	static void Save(double credit = 0.0, int bet = 0, double won = 0.0, 
		std::vector<Card>* = nullptr);
	static Recover Read();

	static std::string DoubleToStr(double num);
	static std::string IntToStr(int num);
};
#endif
