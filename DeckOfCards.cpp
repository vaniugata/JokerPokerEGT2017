// Fig. 8.26: DeckOfCards.cpp
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "DeckOfCards.h"

//конструктор
DeckOfCards::DeckOfCards()
{
	for (int row = 0; row <4; row++)
	{
		for (int col = 0; col < 14; col++)
		{
			deck[row][col] = 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		handSuit[i] = 0;
		handFase[i] = 0;
	}

	srand(time(0));
}
//------------------разбъркваме----------------

void DeckOfCards::shuffle()
{
	int row;
	int col;
	for (int card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			col = rand() % 13;
		} while (deck[row][col] != 0);
		deck[row][col] = card;
	}
}
//------------------раздаваме----------------
void DeckOfCards::deal() {
	static const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades"};//боя
	static const char *face[14] = { "Ace", "Deuce", "Three", "Four", "Five",
			"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King","Joker"  };//вид
	int i = 0;
	for (int card = 0; card < 5; card++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 14; col++)
			{
				if (deck[row][col] == card)
				{
					cout << face[col] << " of "<< suit[row]<<endl;

					handSuit[i] = row;
					handFase[i] = col;
					i++;
				}
			}
		}
	}
}
//------------------Има ли двоика карти от вид----------------
bool DeckOfCards::isPair()
{
	int counters[14] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		switch (handFase[i])
		{
		case 0:	counters[0]++;  break;
		case 1:	counters[1]++;	break;
		case 2: counters[2]++;	break;
		case 3: counters[3]++;	break;
		case 4: counters[4]++;	break;
		case 5: counters[5]++;	break;
		case 6: counters[6]++;	break;
		case 7: counters[7]++;	break;
		case 8: counters[8]++;	break;
		case 9: counters[9]++;	break;
		case 10:counters[10]++;	break;
		case 11:counters[11]++;	break;
		case 12:counters[12]++;	break;
		case 13:counters[13]++;	break;
		}
	}
	for (int i = 0; i < 14; i++)
	{
		if (counters[i] == 2)
			return true;
	}
	return false;
}
//------------------Има ли две двоики----------------
bool DeckOfCards::towPair()
{
	int counters[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		counters[handFase[i]]++;
	}
	for (int i = 0; i < 14; i++)
	{
		int count = 0;
		if (counters[i] == 2)
		{
			count++;
			if (count == 2)
			{
				return true;
			}
		}
	}
	return false;
}
//-----------дали ръката съдържа три карти от един вид------
bool DeckOfCards::threeOfKind()
{
	int counters[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		counters[handFase[i]]++;
	}
	for (int i = 0; i < 14; i++)
	{

		if (counters[i] == 3)
			return true;
	}
	return false;

}
//----дали ръката съдържа четири от един вид------
bool DeckOfCards::fourOfKind()
{
	int counters[13] = { 0 };
		for (int i = 0; i < 5; i++)
		{
			counters[handFase[i]]++;
		}
		for (int i = 0; i < 14; i++)
		{

			if (counters[i] == 4)
				return true;
		}
		return false;

	}
//----------------------флаш-------------------------
bool DeckOfCards::flush()
{
	int counters[4] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		counters[handSuit[i]]++;
	}

	for (int i = 0; i < 4; i++)
	{
		if (counters[i] == 5)
		{
			return true;

		}
		return false;

	}
}
//-------------------стрейт------------------------
bool DeckOfCards::straight()
{
	int counters[14] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		counters[handFase[i]]++;
	}

	for (int i = 0; i < 14 - 4; i++)
	{
		if (counters[i] == 1 &&
				counters[i + 1] == 1 &&
				counters[i + 2] == 1 &&
				counters[i + 3] == 1 &&
				counters[i + 4] == 1)
		{
			return true;
		}
	}
	return false;
}
