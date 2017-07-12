#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
class DeckOfCards
{
private:
	int deck[4][13];
	const int sizeOfSuit = 2;
	const int sizeOfValue = 5;
	int hand[2][5];
public:
	DeckOfCards();
	~DeckOfCards();
	void shuffle();
	void deal();
	bool hasPair();
	bool hasTwoPairs();
	bool hasThreeOfAKind();
	bool hasFourOfAKind();
	bool hasFlush();
	bool hasStraight();
	int* sort();
};
#endif