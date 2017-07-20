#ifndef RECOVERY_H
#define RECOVERY_H
#include "pugixml.hpp"

struct Recover
{
	double credit;
	int bet;
	double win;
};

class Recovery
{
private:
	static pugi::xml_document doc;
public:
	Recovery();
	~Recovery();

	static void InitNewFile();
<<<<<<< HEAD
	static void Save(double credit = 0.0, int bet = 0, double won = 0.0);
=======
	static void Save(double credit = 0.0, int bet = -1, double won = -1.0);
>>>>>>> origin/master
	static Recover Read();

	static std::string DoubleToStr(double num);
	static std::string IntToStr(int num);
};
#endif
