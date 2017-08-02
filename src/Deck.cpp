#include "Deck.h"
#include "Game.h"
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
	m_tArrow.LoadFromFile(renderer, "Resources/arrow.png");

	for(int i = 0; i < 52; i++)
	{ 
		Card currentCard;
		//eCardSuit suit;
		currentCard.setCardSuit(static_cast<eCardSuit> ((i / 13) + 1));
		currentCard.setCardValue(static_cast<eCardValue>((i % 13) + 1));
		deck.push_back(currentCard);
		
	}

	int counter = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++, counter++)
		{
			deck[counter].setCardRect(j * T_CARD_WIDTH, i * T_CARD_HEIGHT,
				T_CARD_WIDTH, T_CARD_HEIGHT);
		}
	}

	Card cardForVector;
	for(int i = 0; i < 5; i++)
	{
		hand.push_back(cardForVector);
	}
	//Joker
	Card currentCard;
	currentCard.setCardSuit(JOKERSUIT);
	currentCard.setCardValue(JOKERVALUE);
	currentCard.setCardRect(0, 4 * T_CARD_HEIGHT, T_CARD_WIDTH, T_CARD_HEIGHT);
	deck.push_back(currentCard);
	//BackCard
	currentCard.setCardSuit(static_cast<eCardSuit>(0));
	currentCard.setCardValue(static_cast<eCardValue>(0));
	currentCard.setCardRect(T_CARD_WIDTH, 4 * T_CARD_HEIGHT, T_CARD_WIDTH, T_CARD_HEIGHT);
	deck.push_back(currentCard);
	
	srand(time(0));
	

	initHoldBtns();
	

}


Deck::~Deck()
{
	std::cout << "Deck deleted.\n";
}


void Deck::deal()
{
	for(int i = 0;i < 5;i++)
	{
		
		int random = rand() % (deck.size()-1);
		Card currentCard = deck[random];

		if(hand[i].getIsHold() == false)
		{ 
			hand[i] = currentCard;	
			hand[i].setCardPosition(static_cast<eCardPosition>(i + 1));
			deck.erase(deck.begin()+random);
		}
		if (hand[i].getIsHold() == true)
		{
			hand[i].setIsHold(false);
		}

	}
	/*for (int i = 0; i < deck.size(); i++)
	{
		std::cout << deck[i].getCardValue() << "  " << deck[i].getCardSuit() << std::endl;
	}*/
	//int card1 = 8;
	//hand[0].setCardValue(TEN);
	//hand[0].setCardSuit(CLUBS);
	//hand[0].setCardRect(deck[card1].getCardRect()->x, deck[card1].getCardRect()->y,
	//	deck[card1].getCardRect()->w, deck[card1].getCardRect()->h);
	//hand[0].setCardPosition(FIRST);

	//int card2 = 9;
	//hand[1].setCardValue(JACK);
	//hand[1].setCardSuit(CLUBS);
	//hand[1].setCardRect(deck[card2].getCardRect()->x, deck[card2].getCardRect()->y,
	//	deck[card2].getCardRect()->w, deck[card2].getCardRect()->h);
	//hand[1].setCardPosition(SECOND);

	//int card3 = 10;
	//hand[2].setCardValue(QUEEN);
	//hand[2].setCardSuit(CLUBS);
	//hand[2].setCardRect(deck[card3].getCardRect()->x, deck[card3].getCardRect()->y,
	//	deck[card3].getCardRect()->w, deck[card3].getCardRect()->h);
	//hand[2].setCardPosition(THIRD);
	//int card4 = 11;
	//hand[3].setCardValue(JOKERVALUE);
	//hand[3].setCardSuit(JOKERSUIT);
	//hand[3].setCardRect(deck[card4].getCardRect()->x, deck[card4].getCardRect()->y,
	//	deck[card4].getCardRect()->w, deck[card4].getCardRect()->h);
	//hand[3].setCardPosition(FOURTH);
	//int card5 = 12;
	//hand[4].setCardValue(KING);
	//hand[4].setCardSuit(CLUBS);
	//hand[4].setCardRect(deck[card5].getCardRect()->x, deck[card5].getCardRect()->y,
	//	deck[card5].getCardRect()->w, deck[card5].getCardRect()->h);
	//hand[4].setCardPosition(FIFTH);
	//printDeck();

	std::cout << "Kill count: " << m_iKillCount << std::endl;
	m_iKillCount++;
}


void Deck::printDeck()
{
	for(int i = 0; i < 5; i++)
	{
		std::cout << "Suit:";
		std::cout << hand[i].getCardSuit();
		std::cout << " Value:";
		std::cout << hand[i].getCardValue();
		std::cout << " IsHold:";
		std::cout << hand[i].getIsHold();
		std::cout << " Position:";
		std::cout << hand[i].getCardPosition();
		std::cout << std::endl;
	}
}

Card Deck::getRandomCard()
{
	Card randomCard;
	int randomIndex = rand() % 53;
	randomCard = deck[randomIndex];
	return randomCard;
}

const ButtonObject* Deck::GetHeldCardsButtons() const
{
	return m_arrCardHold;
}

std::vector<Card>& Deck::GetHand()
{
	return this->hand;
}

void Deck::setHand(std::vector<Card>& hand)
{
	this->hand = hand;
}



int Deck::GetKillCount() const
{
	return this->m_iKillCount;
}



std::vector<Card> Deck::GetSortedHand()

{
	std::vector<Card> sorted = hand;
	
	std::sort(sorted.begin(), sorted.begin() + 5);
	for (int i = 0; i < sorted.size(); i++)
	{
		sorted[i].setIsGood(false);
	}
	
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
		return true;
	}
	return false;
}

void Deck::RenderCard(SDL_Renderer * renderer, SDL_Rect* rect, SDL_Rect* destination)
{
	m_texture.Render(renderer, destination->x, destination->y, destination->w, destination->h, rect);
}

void Deck::RenderHand(SDL_Renderer* renderer, std::vector<Card>& hand)
{
	SDL_Rect cardPlace{ (SCREEN_WIDTH - 5 * CARD_W)/2,350,CARD_W,CARD_H_ };

	for(int i = 0; i < HAND_SIZE; i++)
	{
			RenderCard(renderer, &hand[i].m_cardRect, &cardPlace);
						cardPlace.x += cardPlace.w;
	}
}

void Deck::RenderStart(SDL_Renderer * renderer)
{
	SDL_Rect cardPos{ (SCREEN_WIDTH - 5 * CARD_W) / 2,350,CARD_W,CARD_H_ };
	for(int i = 0; i < HAND_SIZE; i++)
	{
		RenderCard(renderer, &deck[(deck.size()-1)].m_cardRect, &cardPos);

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
		m_arrCardHold[i].SetDimentions(HOLD_W, CARD_H_);
		m_arrCardHold[i].Render(renderer, &clipVisible, x, y, HOLD_W, HOLD_H / 2);
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
		m_arrCardHold[i] = m_currentBtn;
	}
}

void Deck::setCard(Card & card, int index)
{
	hand[index] = card;
}

void Deck::HoldSelectedCards()
{
	for(int i = 0; i < 5; i++)
	{
		if(m_arrCardHold[i].IsSelected() && hand[i].getIsHold() == false)
			hand[i].setIsHold(true);
		else if(m_arrCardHold[i].IsSelected() && hand[i].getIsHold() == true)
			hand[i].setIsHold(false);
		
		std::cout << hand[i].getIsHold();
	}
}

void Deck::DimCards(SDL_Renderer * renderer)
{
	int x = (SCREEN_WIDTH - 5 * CARD_W) / 2;
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand.at(i).getIsGood() == false)
		{
			m_tDim.Render(renderer,x  +  i * CARD_W, 350, CARD_W, CARD_H_);
		}
	}
	
}


void Deck::holdGoodCards(SDL_Renderer* renderer)
{
	SDL_Rect clip{ 0,0,300,150 };
	int x = ((SCREEN_WIDTH - 5 * CARD_W) / 2 + CARD_W / 2);
	for (int i = 0; i <hand.size(); i++)
	{
		if (hand[i].getIsGood() == true)
		{
			if (Game::SwitchFrame(250) == true)
				m_tArrow.Render(renderer, x + i*CARD_W-50, 320, 100, 25, &clip);
			else
				m_tArrow.Render(renderer, x + i*CARD_W - 50, 310, 100, 25, &clip);
		}
			
	}
}

std::vector<Card>Deck::getUsualHand()
{
	std::vector<Card> usualHand = hand;
	sort(usualHand.begin(), usualHand.begin() + 5, [](const Card& left, const Card& right)
	{
		return left.getCardPosition() < right.getCardPosition();
	});
	for (int i = 0; i < hand.size(); i++)
	{
		usualHand[i].setIsGood(false);
	}
	return usualHand;
}

