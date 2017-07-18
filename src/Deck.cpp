#include "Deck.h"
#include<iostream>

	Deck::Deck(SDL_Renderer* renderer) :
	m_texture(renderer),
	m_tHold(renderer),
	m_currentBtn(renderer, "Resources/hold-button.png")
{
	m_texture.LoadFromFile(renderer, "Resources/deckOfCards.png");
	m_tHold.LoadFromFile(renderer, "Resources/hold.png");

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
			deckOfCards[counter].setCardRect(j * T_CARD_WIDTH, i * T_CARD_HEIGHT,
				T_CARD_WIDTH, T_CARD_HEIGHT);
		}
	}

	Card cardForVector;
	for(int i = 0; i < 5; i++)
	{
		hand.push_back(cardForVector);
	}
	//Joker
	deckOfCards[52].setCardSuit(JOKERSUIT);
	deckOfCards[52].setCardValue(JOKERVALUE);
	deckOfCards[52].setCardRect(0, 4 * T_CARD_HEIGHT, T_CARD_WIDTH, T_CARD_HEIGHT);

	deckOfCards[53].setCardSuit(static_cast<eCardSuit>(0));
	deckOfCards[53].setCardValue(static_cast<eCardValue>(0));
	deckOfCards[53].setCardRect(T_CARD_WIDTH, 4 * T_CARD_HEIGHT, T_CARD_WIDTH, T_CARD_HEIGHT);
	
	srand(time(0));
	//BackCard

	initHoldBtns();
	

}


Deck::~Deck()
{
	std::cout << "Deck deleted.\n";
}


void Deck::deal()
{
	printDeck();
	for(int i = 0;i < 5;i++)
	{
		Card currentCard = deckOfCards[rand() % 53];
		
		if(hand[i].getIsHold() == false && isCardInHand(currentCard) == false)
		{
			hand[i] = currentCard;
		}

		if (hand[i].getIsHold() == true)
		{
			hand[i].setIsHold(false);
		}
	}
	std::cout << "--------------------------------------" << std::endl;

	printDeck();

	m_iKillCount++;

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

const ButtonObject* Deck::GetHeldCardsButtons() const
{
	return m_vecCardHold;
}

const std::vector<Card>& Deck::GetHand() const
{
	return this->hand;
}



int Deck::GetKillCount() const
{
	return this->m_iKillCount;
}



std::vector<Card> Deck::GetSortedHand()

{
	std::vector<Card> sorted = hand;
	
	std::sort(sorted.begin(), sorted.begin() + 5);
	return sorted;

}

int Deck::evaluateHand()
{
	std::vector<Card> sorted = GetSortedHand();

	int royalFlush, full, fourOfAKind, straight, flush, threeOfKind, pair, KingOrBetter, fiveOfAKind;
	fourOfAKind = royalFlush = full = straight = flush = threeOfKind = pair = KingOrBetter = fiveOfAKind = 0;
	k = 0;
	//checks for flush
	while(k < 4 && sorted[k].getCardSuit() == sorted[k + 1].getCardSuit())

		k++;
	isJokerHand();
	if(k == 4)
		flush = 1;

	//checks for straight
	k = 0;

	while(k < 4 && sorted[k].getCardValue() == sorted[k + 1].getCardValue() - 1)
	{
		if(sorted[0].getCardValue() == DEUCE && sorted[4].getCardValue() == ACE && k == 2)

		{
			k++;
		}
		k++;
	}
	//check for 2 3 5 A Joker

	if(sorted[0].getCardValue() == DEUCE && sorted[3].getCardValue() == ACE && k == 1)
	{
		if(sorted[2].getCardValue() == FIVE)

			k += 2;
		isJokerHand();
	}
	if(k == 4)
		straight = 1;
	//chech for four of a kind
	for(int i = 0; i < 2; i++)
	{
		k = i;

		while(k < i + 3 && sorted[k].getCardValue() == sorted[k + 1].getCardValue())

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

			while(k < i + 2 && sorted[k].getCardValue() == sorted[k + 1].getCardValue())

			{
				k++;
			}
			isJokerHand();
			if(k == i + 2)
			{
				threeOfKind = 1;
				if(i == 0)
				{

					if(sorted[3].getCardValue() == sorted[4].getCardValue()) {

						full = 1;
					}
				}
				else if(i == 1) {

					if(sorted[0].getCardValue() == sorted[4].getCardValue()) {

						full = 1;
					}
				}
				else {

					if(sorted[0].getCardValue() == sorted[1].getCardValue())

						full = 1;
				}
			}

		}
	}

	if(straight && flush && sorted[0].getCardValue() == TEN) {

		return 0;
	}
	else if(fiveOfAKind)
	{
		return 1;
	}

	else if(straight && flush && isJokerHand() && sorted[0].getCardValue() == TEN)

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

		if(sorted[k].getCardValue() == sorted[k + 1].getCardValue())

			pair++;
	}
	if(pair == 2) {
		return 9;
	}

	else if (sorted[3].getCardValue() >= KING)
	{
		if (isJokerHand())
			return 10;
		if (sorted[3].getCardValue() == sorted[4].getCardValue())
			return 10;
		return -1;

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

	SDL_Rect cardPlace{ (SCREEN_WIDTH - 5 * CARD_W)/2,350,CARD_W,CARD_H_ };

	for(int i = 0; i < 5; i++)
	{
		RenderCard(renderer, hand[i].getCardRect(), &cardPlace);
		cardPlace.x += cardPlace.w;
	}

	
}

void Deck::RenderHoldBtns(SDL_Renderer * renderer)
{

	SDL_Rect  clipVisible {0,0, HOLD_W, HOLD_H / 2 };
	int x= (SCREEN_WIDTH - 5 * CARD_W) / 2;
	int y = 350;

	for (int i = 0; i <5; i++)
	{
		m_vecCardHold[i].SetDimentions(HOLD_W, HOLD_H /2);
		m_vecCardHold[i].Render(renderer, &clipVisible, x, y, HOLD_W, HOLD_H / 2);
		//render the picture
		if(hand[i].getIsHold())
		{
			m_tHold.Render(renderer, x, y + 50, m_tHold.GetWidth() / 2, m_tHold.GetHeight() / 2);
		}
		x += HOLD_W + 2;
	}
}

void Deck::RenderHoldStamps(SDL_Renderer * renderer)
{
	int x = 50;
	int y = 460;

	for(int i = 0; i < 5; i++)
	{
		if(hand[i].getIsHold())
		{
			
			x += HOLD_W + 2;
		}
	}
}

void Deck::initHoldBtns()
{
	for (int i = 0; i < 5; i++)
	{
		m_vecCardHold[i] = m_currentBtn;
	}
}

void Deck::HoldSelectedCards()
{
	if(m_iKillCount >= 2) {	return; }

	for(int i = 0; i < 5; i++)
	{
		if(m_vecCardHold[i].IsSelected() && hand[i].getIsHold() == false)
			hand[i].setIsHold(true);
		else if(m_vecCardHold[i].IsSelected() && hand[i].getIsHold() == true)
			hand[i].setIsHold(false);
		
		std::cout << hand[i].getIsHold();
	}
}

void Deck::render_card_from_deck(SDL_Renderer* renderer, int i)
{
	SDL_Rect onscreen{ 0,0, T_CARD_WIDTH , T_CARD_HEIGHT };
	RenderCard(renderer, deckOfCards[i].getCardRect(), &onscreen);
	std::cout << "CURENT CARD: " << deckOfCards[i].getCardSuit() << " " << deckOfCards[i].getCardValue() << "\n";
}

