// Fig. 8.25: DeckOfCards.h
// Definition of class DeckOfCards that
// represents a deck of playing cards.
#include <iostream>
using namespace std;

class DeckOfCards
{
public:
   DeckOfCards();//конструктор

   void shuffle();//разбърква картите
   void deal();//роздава 5 карти
   bool isPair();//Има ли двоика
   bool towPair();//Има ли две двоики
   bool threeOfKind();//дали ръката съдържа три от един вид
   bool fourOfKind();//дали ръката съдържа четири от един вид
   bool flush();//флаш
   bool straight();//стрейт

private:
   int deck[ 4 ][ 13 ];
   int handSuit[5];
   int handFase[5];
};



