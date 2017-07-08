#ifndef PAYTABLE_OBJECT_H
#define PAYTABLE_OBJECT_H
#include "Texture.h"
#include <SDL_ttf.h>
#include <vector>

class PaytableObject
{
private:
	const int X_BORDER_OFFSET = 25;
	const int Y_BORDER_OFFSET = 10;

	Texture m_texture;
	Texture m_tText;
	TTF_Font* m_font;
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
	~PaytableObject();

	void InitFont(std::string path);
	void Render(SDL_Renderer* renderer);
	void RenderCardCombinations(SDL_Renderer* renderer);
	void RenderBetList(SDL_Renderer* renderer);

	//logic
	void IncreaseBet();
};
#endif