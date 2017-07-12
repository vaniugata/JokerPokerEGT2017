#include "DeckOfCards.h"
#include <iostream>
using std::cout;
using std::left;
using std::right;
#include <iomanip>
using std::setw;

#include <cstdlib> // prototypes for rand and srand
using std::rand;
using std::srand;

#include <ctime> // prototype for time
using std::time;

DeckOfCards::DeckOfCards()
{
	//Intialize the hand array to 0;
	for(int i = 0; i < sizeOfSuit; ++i)
	{
		for(int j = 0; j < sizeOfValue; ++j)
		{
			this->hand[i][j] = 0;
		}
	}

	// loop through rows of deck
	for(int row = 0; row <= 3; row++)
	{
		// loop through columns of deck for current row
		for(int column = 0; column <= 12; column++)
		{
			deck[row][column] = 0; // initialize slot of deck to 0
		} // end inner for
	} // end outer for

	srand(time(0)); // seed
}

DeckOfCards::~DeckOfCards()
{
	std::cout << "Deleted DeckOfCards.\n";
}

void DeckOfCards::shuffle()
{
	int row; // represents suit value of card
	int column; // represents face value of card

				// for each of the 52 cards, choose a slot of the deck randomly
	for(int card = 1; card <= 52; card++)
	{
		do // choose a new random location until unoccupied slot is found
		{
			row = rand() % 4; // randomly select the row
			column = rand() % 13; // randomly select the column
		} while(deck[row][column] != 0); // end do...while

										 // place card number in chosen slot of deck
		deck[row][column] = card;
	} // end for
} // end function shuffle

void DeckOfCards::deal()
{
	// initialize suit array
	static const char *suit[4] =
	{ "Hearts", "Diamonds", "Clubs", "Spades" };

	// initialize face array
	static const char *face[13] =
	{ "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
		"Ten", "Jack", "Queen", "King", "Ace" };

	// for each of the 52 cards
	for(int card = 1; card <= 5; card++)
	{
		// loop through rows of deck
		for(int row = 0; row <= 3; row++)
		{
			// loop through columns of deck for current row
			for(int column = 0; column <= 12; column++)
			{
				// if slot contains current card, display card
				if(deck[row][column] == card)
				{
					std::cout << setw(5) << right << face[column] << " of "
						<< setw(8) << left << suit[row] << std::endl;
					hand[0][card - 1] = row;
					hand[1][card - 1] = column;
				} // end if
			} // end innermost for
		} // end inner for
	} // end outer for
} // end func

bool DeckOfCards::hasPair()
{
	for(int i = 0; i < 5; ++i)
	{
		for(int j = i + 1; j < 5; ++j)
		{
			if(hand[1][i] == hand[1][j])
			{
				return true;
			}
		}
	}

	return false;
}

bool DeckOfCards::hasTwoPairs()
{
	int pair = 0;

	for(int i = 0; i < 5; ++i)
	{
		for(int j = i + 1; j < 5; ++j)
		{
			if(hand[1][i] == hand[1][j])
			{
				pair++;
			}
		}
	}

	return pair == 2 ? true : false;
}

bool DeckOfCards::hasThreeOfAKind()
{
	int equalCardsCount = 0;

	for(int i = 0; i < 5; ++i)
	{
		for(int j = i + 1; j < 5; ++j)
		{
			if(hand[1][i] == hand[1][j])
			{
				equalCardsCount++;
			}
		}
	}

	return equalCardsCount == 3 ? true : false;
}

bool DeckOfCards::hasFourOfAKind()
{
	int streak = 1;
	for(int i = 0; i < 5; i++)
	{
		for(int j = i + 1; j < 5; ++j)
		{
			if(hand[1][i] == hand[1][j])
			{
				i = j;
				streak++;
			}
		}
	}

	return streak == 4 ? true : false;
}

bool DeckOfCards::hasFlush()
{
	bool isEqual = false;
	for(int i = 0; i < sizeOfValue; ++i)
	{
		for(int j = i + 1; j < sizeOfValue; ++j)
		{
			if(hand[0][i] == hand[0][j])
				isEqual = true;
			else
				return false;
		}
	}

	return isEqual;
}

bool DeckOfCards::hasStraight()
{
	int* sortedHand = this->sort();
	bool hasStraight = false;

	for(int i = 0; i < sizeOfValue - 1; ++i)
	{
		if(sortedHand[i] + 1 == sortedHand[i + 1])
			hasStraight = true;
		else
			return false;
	}

	return hasStraight;
}

int* DeckOfCards::sort()
{
	int* sortedHand = new int[sizeOfValue];
	for(int i = 0; i < sizeOfValue; ++i)
		sortedHand[i] = hand[1][i];


	for(int i = 1; i < sizeOfValue; ++i)
	{
		int index = sortedHand[i];
		int dec = i;
		while(dec > 0 && sortedHand[dec - 1] >= index)
		{
			sortedHand[dec] = sortedHand[dec - 1];
			--dec;
		}
		sortedHand[dec] = index;
	}

	return sortedHand;
}


