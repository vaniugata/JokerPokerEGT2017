#include "Game.h"
#include "Globals.h"
#include "Texture.h"
#include "Intro.h"
#include "Deck.h"

eGameState gGameState;

int main(int args, char* argc[])
{
	Game game;
	Intro intro = Intro(game.GetRenderer(), game.m_event, game.m_eGameState, game.GetCredit());

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
				std::cout << "Bonus state.";
				break;

			}
		} //event loop
		
	} // run loop
		
	
	return 0;
}