#ifndef  DECK_H
#define DECK_H
#include "Card.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include "Texture.h"
#include "ButtonObject.h"
class Deck
{
private:
	int m_iKillCount;
public:
	Texture m_texture;
private:
	Texture m_tHold;
	Texture m_tDim;
	Texture m_tArrow;
	std::vector<Card> deck;
	Card deckOfCards[54];
	std::vector<Card> hand;
public:
	ButtonObject m_currentBtn;
	ButtonObject m_arrCardHold[5];

public:
	Deck(SDL_Renderer*);
	~Deck();

	void deal();
	void printDeck();

	//getters
	Card getRandomCard();

	const ButtonObject* GetHeldCardsButtons() const;

	std::vector<Card>& GetHand();

	void setHand(std::vector<Card>& hand);
	int GetKillCount() const;

	std::vector<Card> GetSortedHand();

	bool isCardInHand(Card& card);
	bool isJokerHand();
	void RenderCard(SDL_Renderer*,SDL_Rect*,SDL_Rect*);
	void RenderHand(SDL_Renderer* renderer, std::vector<Card>& hand);
	void RenderStart(SDL_Renderer* renderer);
	void RenderHoldBtns(SDL_Renderer*);
	void RenderHoldStamps(SDL_Renderer* renderer);
	void initHoldBtns();
	void setCard(Card& card, int index);
	void HoldSelectedCards();
	void DimCards(SDL_Renderer* renderer);
	void holdGoodCards(SDL_Renderer*);
	std::vector<Card> getUsualHand();
};
#endif 

