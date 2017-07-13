#ifndef PAYTABLE_OBJECT_H
#define PAYTABLE_OBJECT_H
#include "Texture.h"
#include "ButtonObject.h"
#include "includesSDL2.h"

#include <vector>

class PaytableObject
{
private:
	Texture m_texture;
	Texture m_tText;
	TTF_Font* m_font;
	ButtonObject m_btnBetOne;
	ButtonObject m_btnbetMax;
	static int oldCoef;
	static int coef;
	SDL_Color color{ 255, 255, 255 };

	std::vector<std::string> m_vecHands
	{
		"Natural royal flush",
		"Five of a kind",
		"Joker royal flush",
		"Straight flush",
		"Four of a kind",
		"Full house",
		"Flush",
		"Straight",
		"Three of a kind",
		"Two pair",
		"Kings or better"
	};
	std::vector<int> m_vecBets {800, 130, 100, 50, 20, 7, 5, 3, 2, 1, 1};

public:
	PaytableObject(SDL_Renderer* renderer);
	virtual~PaytableObject();

	//getters
	ButtonObject& GetBetOneBtn();
	ButtonObject& GetBetMaxBtn();

	void InitFont(std::string path);
	void Render(SDL_Renderer* renderer);
	void RenderCardCombinations(SDL_Renderer* renderer);
	void RenderBetList(SDL_Renderer* renderer,int index);
	

	//logic
	void IncreaseBet();
	void SetMaxBet();
};
#endif
