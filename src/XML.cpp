#include "XML.h"
#include <string>
#include <sstream>

float credit = 100;
int bet = 5;
float won = 50;
std::string cardHand[5] = { "2","3","10","J","8"}; //?

XML::XML() {
}

std::string XML::IntToString(int x) const {
	std::stringstream ss;
	ss << x;
	std::string res = ss.str();
	return res;
}

std::string XML::FloatToString(float x) const {
	std::stringstream ss;
	ss << x;
	std::string res = ss.str();
	return res;
}

void XML::Save_XML() {
	//Specification node
	pugi::xml_node root = doc.append_child(pugi::node_declaration);
	root.append_attribute("version") = "1.0";
	root.append_attribute("encoding") = "utf-8";

	//Main node
	pugi::xml_node node = doc.append_child("recovery");

	//Credits
	pugi::xml_node credits = node.append_child("credit");
	credits.append_child(pugi::node_pcdata).set_value(FloatToString(credit).c_str());
	pugi::xml_node bets = node.append_child("bet");
	bets.append_child(pugi::node_pcdata).set_value(IntToString(bet).c_str());
	pugi::xml_node wons = node.append_child("won");
	wons.append_child(pugi::node_pcdata).set_value(FloatToString(won).c_str());
	//Cards
	pugi::xml_node flag = node.append_child("CardsHand");

	for (int i = 0; i < 5; i++) {
		flag.append_child(pugi::node_pcdata).set_value(cardHand[i].c_str());
	}

	doc.save_file("Recovery.xml");
}

