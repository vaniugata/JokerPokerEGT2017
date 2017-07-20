#include "Recovery.h"
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

pugi::xml_document Recovery::doc;

Recovery::Recovery() {
}

Recovery::~Recovery() {
	std::cout << "Deleted Recovery.\n";
}

void Recovery::InitNewFile() {
	doc.reset();
	doc.save_file("Recovery.xml");
	//Specification node
	pugi::xml_node root = doc.append_child(pugi::node_declaration);
	root.append_attribute("version") = "1.0";
	root.append_attribute("encoding") = "utf-8";

	doc.save_file("Recovery.xml");
}

void Recovery::Save(double credit, int bet, double won) {
	pugi::xml_node node = doc.append_child("recovery");


if(credit > 0)
{
		pugi::xml_node credits = node.append_child("credit");

		// we can't change value of the element or name of the comment
		credits.append_child(pugi::node_pcdata).set_value(
				DoubleToStr(credit).c_str());
		credits.set_value(DoubleToStr(credit).c_str());

}
if (bet >= 0) {
	pugi::xml_node bets = node.append_child("bet");
	bets.append_child(pugi::node_pcdata).set_value(IntToStr(bet).c_str());
}
if (won >= 0) {
	pugi::xml_node wons = node.append_child("won");
	wons.append_child(pugi::node_pcdata).set_value(DoubleToStr(won).c_str());
}

doc.save_file("Recovery.xml");
}

Recover Recovery::Read() {
if (!doc.load_file("Recovery.xml")) {
	std::cout << "Failed to open Recovery.xml.";
	return Recover { -1, -1, -1 };
}

Recover recover;

pugi::xml_node current = doc.child("recovery");

recover.credit = current.child("credit").text().as_double();
recover.bet = current.child("bet").text().as_int();
recover.win = current.child("win").text().as_double();

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
