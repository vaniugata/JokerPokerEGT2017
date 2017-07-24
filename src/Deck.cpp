#include "Deck.h"
#include<iostream>

Deck::Deck(SDL_Renderer* renderer) :
	m_texture(renderer),
	m_tHold(renderer),
	m_currentBtn(renderer, "Resources/hold-button.png"),
	m_iKillCount(0)
{
	m_texture.LoadFromFile(renderer, "Resources/deckOfCards.png");
	m_tHold.LoadFromFile(renderer, "Resources/hold.png");
	m_tDim.LoadFromFile(renderer, "Resources/dimCard.png");
	m_tDim.SetAlpha(100);
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
	//printDeck();
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
	//std::cout << "--------------------------------------" << std::endl;
	//printDeck();
	std::cout << "Kill count: " << m_iKillCount << std::endl;
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
	int k = 0;
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

void Deck::RenderStart(SDL_Renderer * renderer)
{
	SDL_Rect cardPos{ (SCREEN_WIDTH - 5 * CARD_W) / 2,350,CARD_W,CARD_H_ };
	for(int i = 0; i < HAND_SIZE; i++)
	{
		RenderCard(renderer, deckOfCards[53].getCardRect(), &cardPos);
		cardPos.x += CARD_W;
	}
}

void Deck::RenderHoldBtns(SDL_Renderer * renderer)
{

	SDL_Rect  clipVisible {0,0, HOLD_W, CARD_H_};
	int x= (SCREEN_WIDTH - 5 * CARD_W) / 2;
	int y = 350;

	for (int i = 0; i <5; i++)
	{
		//set dimentions for clicking logic
		m_vecCardHold[i].SetDimentions(HOLD_W, CARD_H_);
		m_vecCardHold[i].Render(renderer, &clipVisible, x, y, HOLD_W, HOLD_H / 2);
		//render the picture
		if(hand[i].getIsHold())
		{
			//show golden hold stamp
			m_tHold.Render(renderer, x, y + 50, m_tHold.GetWidth() / 2, m_tHold.GetHeight() / 2);
		}
		//move to the next card
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
	for(int i = 0; i < 5; i++)
	{
		if(m_vecCardHold[i].IsSelected() && hand[i].getIsHold() == false)
			hand[i].setIsHold(true);
		else if(m_vecCardHold[i].IsSelected() && hand[i].getIsHold() == true)
			hand[i].setIsHold(false);
		
		std::cout << hand[i].getIsHold();
	}
}

void Deck::DimCards(SDL_Renderer * renderer)
{
	int x = (SCREEN_WIDTH - 5 * CARD_W) / 2;
	m_tDim.Render(renderer, x + CARD_W, 350, CARD_W, CARD_H_);
}

void Deck::render_card_from_deck(SDL_Renderer* renderer, int i)
{
	SDL_Rect onscreen{ 0,0, T_CARD_WIDTH , T_CARD_HEIGHT };
	RenderCard(renderer, deckOfCards[i].getCardRect(), &onscreen);
	std::cout << "CURENT CARD: " << deckOfCards[i].getCardSuit() << " " << deckOfCards[i].getCardValue() << "\n";
}

