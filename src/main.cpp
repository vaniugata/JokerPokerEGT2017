#include "Game.h"
#include "Globals.h"
#include "Texture.h"
#include "Intro.h"
#include "Deck.h"

eGameState gGameState;

int main(int args, char* argc[])
{
	Game game;
	Intro intro = Intro(game.GetRenderer(), game.m_event, game.m_eGameState );
	Deck deck;
	//deck.printDeck();
	deck.deal();
	std::cout << "--------------------------------" << std::endl;
	deck.printDeck();
	switch (deck.evaluateHand()) {
	case 1: std::cout << "KingsOrBetter" << std::endl; break;
	case 2: std::cout << "Pair" << std::endl; break;
	case 3: std::cout << "Two pairs" << std::endl; break;
	case 4: std::cout << "Three of a kind" << std::endl; break;
	case 5: std::cout << "Straight" << std::endl; break;
	case 6: std::cout << "Flush" << std::endl; break;
	case 7: std::cout << "Full house" << std::endl; break;
	case 8: std::cout << "Four of a kind" << std::endl; break;
	case 9: std::cout << "Straight flush" << std::endl; break;
	case 10: std::cout << "Royal flush" << std::endl; break;
	default: std::cout << "ERROR" << std::endl; break;

	}
	std::cout << "--------------------------------" << std::endl;
	deck.printDeck();
	while(game.m_eGameState != QUIT)
	{
 		while(SDL_PollEvent(&game.m_event) > 0)
		{
			switch(game.m_eGameState)
			{
			case INTRO:
				intro.Render();
				intro.HandleEvent();
				intro.Draw();
				break;

			case PLAY:

				game.RenderBonusGame();


				game.Render();
				game.HandleEvent();
				game.Draw();
				break;
			}
			
		} //event loop	
	} // run loop
		
	
	return 0;
}