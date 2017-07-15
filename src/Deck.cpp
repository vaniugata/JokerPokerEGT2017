#include "Deck.h"
#include<iostream>

Deck::Deck(SDL_Renderer* renderer)
	:m_texture(renderer)
{
	m_texture.LoadFromFile(renderer, "Resources/DeckOfCards.png");
	for(int i = 0; i < 52; i++)
	{
		eCardSuit suit;
		deckOfCards[i].setCardSuit(static_cast<eCardSuit> ((i / 13) + 1));
		deckOfCards[i].setCardValue(static_cast<eCardValue>((i % 13) + 1));
	}
	int counter = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++, counter++)
		{
			deckOfCards[counter].setCardRect(j * 168, i * 243, 168, 243);
		}

	}
	Card cardForVector;
	for(int i = 0; i < 5; i++)
	{
		hand.push_back(cardForVector);
	}
	//Joker
	deckOfCards[52].setCardSuit(static_cast<eCardSuit>(5));
	deckOfCards[52].setCardValue(static_cast<eCardValue>(15));

	srand(time(0));
	//BackCard
}

void Deck::deal()
{
	for(int i = 0;i < 5;i++)
	{
		Card currentCard = deckOfCards[rand() % 52];

		if(hand[i].getIsHold() == false && isCardInHand(currentCard) == false)
		{
			hand[i] = currentCard;
		}
	}

	printDeck();
}


void Deck::printDeck()
{
	for(int i = 0; i < 5; i++)
	{
		std::cout << hand[i].getCardSuit();
		std::cout << "  ";
		std::cout << hand[i].getCardValue();
		std::cout << std::endl;
	}
}

Card Deck::getRandomCard()
{
	Card randomCard;
	int randomIndex = rand() % 53;
	randomCard = deckOfCards[randomIndex];
	return randomCard;
}

void Deck::sortHand()
{
	std::sort(hand.begin(), hand.begin() + 5);
}

int Deck::evaluateHand()
{
	sortHand();
	int royalFlush, full, fourOfAKind, straight, flush, threeOfKind, pair, KingOrBetter, fiveOfAKind;
	fourOfAKind = royalFlush = full = straight = flush = threeOfKind = pair = KingOrBetter = fiveOfAKind = 0;
	k = 0;
	//checks for flush
	while(k < 4 && hand[k].getCardSuit() == hand[k + 1].getCardSuit())
		k++;
	isJokerHand();
	if(k == 4)
		flush = 1;

	//checks for straight
	k = 0;
	while(k < 4 && hand[k].getCardValue() == hand[k + 1].getCardValue() - 1)
	{
		if(hand[0].getCardValue() == DEUCE && hand[4].getCardValue() == ACE && k == 2)
		{
			k++;
		}
		k++;
	}
	//check for 2 3 5 A Joker
	if(hand[0].getCardValue() == DEUCE && hand[3].getCardValue() == ACE && k == 1)
	{
		if(hand[2].getCardValue() == FIVE)
			k += 2;
		isJokerHand();
	}
	if(k == 4)
		straight = 1;
	//chech for four of a kind
	for(int i = 0; i < 2; i++)
	{
		k = i;
		while(k < i + 3 && hand[k].getCardValue() == hand[k + 1].getCardValue())
			k++;
		isJokerHand();
		if(k == i + 3)
			fourOfAKind = 1;
		if(k == i + 4)
			fiveOfAKind = 1;
	}
	//check for three and full
	if(!fourOfAKind) {
		for(int i = 0; i < 3; i++)
		{
			k = i;
			while(k < i + 2 && hand[k].getCardValue() == hand[k + 1].getCardValue())
			{
				k++;
			}
			isJokerHand();
			if(k == i + 2)
			{
				threeOfKind = 1;
				if(i == 0)
				{
					if(hand[3].getCardValue() == hand[4].getCardValue()) {
						full = 1;
					}
				}
				else if(i == 1) {
					if(hand[0].getCardValue() == hand[4].getCardValue()) {
						full = 1;
					}
				}
				else {
					if(hand[0].getCardValue() == hand[1].getCardValue())
						full = 1;
				}
			}

		}
	}
	if(straight && flush && hand[0].getCardValue() == TEN) {
		return 0;
	}
	else if(fiveOfAKind)
	{
		return 1;
	}
	else if(straight && flush && isJokerHand() && hand[0].getCardValue() == TEN)
	{
		return 2;
	}
	else if(straight && flush)
	{
		return 3;
	}
	else if(fourOfAKind) {
		return 4;
	}
	else if(full) {
		return 5;
	}
	else if(flush) {
		return 6;
	}
	else if(straight) {
		return 7;
	}
	else if(threeOfKind) {
		return 8;
	}
	for(k = 0; k < 4; k++) {
		if(hand[k].getCardValue() == hand[k + 1].getCardValue())
			pair++;
	}
	if(pair == 2) {
		return 9;
	}
	else if((pair = 1 && hand[3].getCardValue() >= KING) || (hand[3].getCardValue() >= KING &&  isJokerHand()))
	{
		return 10;
	}
	else return -1;
}

bool Deck::isCardInHand(Card& card)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i] == card) { return true; }
	}

	return false;
}

bool Deck::isJokerHand()
{
	if(hand[4].getCardValue() == JOKERVALUE) {
		k++;
		return true;
	}
	return false;
}

void Deck::RenderCard(SDL_Renderer * renderer, SDL_Rect* rect, SDL_Rect* destination)
{
	m_texture.Render(renderer, destination->x, destination->y, destination->w, destination->h, rect);

}

void Deck::RenderHand(SDL_Renderer * renderer)
{
	SDL_Rect cardPlace{ 50,420,170,240 };
	for(int i = 0; i < 5; i++)
	{
		RenderCard(renderer, &hand[i].getCardRect(), &cardPlace);
		cardPlace.x += cardPlace.w;
	}
}
