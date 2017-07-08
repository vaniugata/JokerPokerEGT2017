#ifndef PAYTABLE_OBJECT_H
#define PAYTABLE_OBJECT_H
#include "Texture.h"
#include <SDL_ttf.h>
#include <vector>

struct bet
{
	int value;
	std::string text;
};

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
	std::vector<bet> m_vecBets
	{
		bet{ 800, "800" },
		bet{ 130, "130" },
		bet{ 100, "100" },
		bet{ 50, "50" },
		bet{ 20, "20" },
		bet{ 7, "7" },
		bet{ 5, "5" },
		bet{ 3, "3" },
		bet{ 2, "2" },
		bet{ 1, "1123" },
		bet{ 1, "1" },
	};

	int m_iBetCount;

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