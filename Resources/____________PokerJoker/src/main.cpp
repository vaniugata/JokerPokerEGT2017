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
	//deck.sortHand();
   std::cout<<deck.evaluateHand();
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
				game.Render();
				game.HandleEvent();
				game.Draw();
				break;

			case BONUS:
				game.RenderBonusGame();
				game.HandleEvent();
				game.Draw();
				break;

			}
			
		} //event loop	
	} // run loop
		
	
	return 0;
}
