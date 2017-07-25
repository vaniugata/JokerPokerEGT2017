#include "Recovery.h"
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

Recovery::Recovery() {
}

Recovery::~Recovery() {
	std::cout << "Deleted Recovery.\n";
}


void Recovery::Save(double credit, int bet, double won) 
{
	static double Credit = 0.0;
	static int Bet = 0;
	static double Won = 0.0;
	if(credit > 0) { Credit = credit; }
	if(bet > 0) { Bet = bet; }
	if(won > 0) { Won = won; }

	pugi::xml_document doc;

	//Specification node
	pugi::xml_node node_root = doc.append_child(pugi::node_declaration);
	node_root.append_attribute("version") = "1.0";
	node_root.append_attribute("encoding") = "utf-8";

	pugi::xml_node node_recovery = doc.append_child("recovery");
	pugi::xml_node node_credit = node_recovery.append_child("credit");
	node_credit.append_child(pugi::node_pcdata).set_value(DoubleToStr(Credit).c_str());

	pugi::xml_node node_bet = node_recovery.append_child("bet");
	node_bet.append_child(pugi::node_pcdata).set_value(IntToStr(Bet).c_str());

	pugi::xml_node node_win = node_recovery.append_child("win");
	node_win.append_child(pugi::node_pcdata).set_value(DoubleToStr(Won).c_str());

	doc.save_file("Recovery.xml");
}

Recover Recovery::Read()
{
	Recover recover;
	pugi::xml_document doc;

	if(doc.load_file("Recovery.xml") == false)
	{
		std::cout << "Could not read Recovery.xml!";
	}

	pugi::xml_node node_recovery = doc.child("recovery");
	recover.credit = node_recovery.child("credit").text().as_double();
	recover.bet = node_recovery.child("bet").text().as_int();
	recover.win = node_recovery.child("win").text().as_double();


	std::cout << recover.credit << " " << recover.bet << " " << recover.win << "!!!!";

	return recover;
}

std::string Recovery::DoubleToStr(double num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

std::string Recovery::IntToStr(int num) {
std::stringstream ss;
ss << num;
return ss.str();
}
