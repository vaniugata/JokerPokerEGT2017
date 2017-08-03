#include "Recovery.h"
#include "Globals.h"
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


void Recovery::Save(double credit, int bet, double won, std::vector<Card>* hand) 
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

	pugi::xml_node node_hand = node_recovery.append_child("hand");
	for(int i = 0; i < HAND_SIZE; i++)
	{
		pugi::xml_node node_card = node_hand.append_child("card");

		if(hand != nullptr)
		{
			pugi::xml_node node_suit = node_card.append_child("suit");
			node_suit.append_child(pugi::node_pcdata)
				.set_value(IntToStr(static_cast<int>(hand->at(i).getCardSuit())).c_str());

			pugi::xml_node node_value = node_card.append_child("value");
			node_value.append_child(pugi::node_pcdata)
				.set_value(IntToStr(static_cast<int>(hand->at(i).getCardValue())).c_str());

			pugi::xml_node node_rect = node_card.append_child("rect");
				pugi::xml_node node_x = node_rect.append_child("x");
				node_x.append_child(pugi::node_pcdata)
					.set_value(IntToStr(hand->at(i).m_cardRect.x).c_str());
				pugi::xml_node node_y = node_rect.append_child("y");
				node_y.append_child(pugi::node_pcdata)
					.set_value(IntToStr(hand->at(i).m_cardRect.y).c_str());
				pugi::xml_node node_w = node_rect.append_child("w");
				node_w.append_child(pugi::node_pcdata)
					.set_value(IntToStr(hand->at(i).m_cardRect.w).c_str());
				pugi::xml_node node_h = node_rect.append_child("h");
				node_h.append_child(pugi::node_pcdata)
					.set_value(IntToStr(hand->at(i).m_cardRect.h).c_str());

				pugi::xml_node node_held = node_card.append_child("held");
				node_held.append_child(pugi::node_pcdata)
					.set_value(IntToStr(hand->at(i).getIsHold()).c_str());

				pugi::xml_node node_autohold = node_card.append_child("autohold");
				node_autohold.append_child(pugi::node_pcdata)
					.set_value(IntToStr(hand->at(i).getIsGood()).c_str());

				pugi::xml_node node_pos = node_card.append_child("position");
				node_pos.append_child(pugi::node_pcdata)
					.set_value(IntToStr(static_cast<int>(hand->at(i).getCardPosition())).c_str());
		}
	}

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

	pugi::xml_node node_hand = node_recovery.child("hand");

	for(pugi::xml_node node_card = node_hand.child("card"); node_card;
		node_card = node_card.next_sibling("card"))
	{
		eCardSuit suit = static_cast<eCardSuit>
			(node_card.child("suit").text().as_int());

		eCardValue value = static_cast<eCardValue>
			(node_card.child("value").text().as_int());

		SDL_Rect rect;
		rect.x = node_card.child("rect").child("x").text().as_int();		
		rect.y = node_card.child("rect").child("y").text().as_int();
		rect.w = node_card.child("rect").child("w").text().as_int();
		rect.h = node_card.child("rect").child("h").text().as_int();
		bool isHold = node_card.child("held").text().as_bool();
		bool autohold = node_card.child("autohold").text().as_bool();

		eCardPosition pos = static_cast<eCardPosition> 
			(node_card.child("position").text().as_int());

		Card card = Card(suit, value, rect, pos, isHold, autohold);
		recover.hand.push_back(card);
	}

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
