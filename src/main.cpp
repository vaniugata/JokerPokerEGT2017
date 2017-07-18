#include "Game.h"
#include "Globals.h"
#include "Texture.h"
#include "Intro.h"
#include "Deck.h"
eGameState gGameState;

int main(int args, char* argc[])
{
	Game game;
	Intro intro = Intro(game.GetRenderer(), game.m_event, game.m_eGameState,game.GetCredit());
	BonusGame bonus = BonusGame(game.GetRenderer(), game.m_event, game.m_eGameState,game.GetCredit() );
	WinBonus win = WinBonus(game.GetRenderer(),game.m_event, game.m_eGameState );
	//Current animation frame
	int frame = 0;
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
				bonus.Render();
				bonus.HandleEvent();
				bonus.Draw();
				break;

			case WIN:
				win.Render();
				win.HandleEvent();
				win.Draw();
				break;

			}
		} //event loop
		
	} // run loop
		
	

	return 0;
}
