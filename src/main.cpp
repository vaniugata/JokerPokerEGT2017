#include "Game.h"
#include "Globals.h"
#include "Texture.h"
#include "Intro.h"
#include "Deck.h"
#include "OutroScreen.h"
#include "Music.h"
#include "Recovery.h"

int main(int args, char* argc[])
{
	Game game;
	Intro intro = Intro(game.GetRenderer(), game.m_event, game.m_eGameState,game.GetCredit());
	BonusGame bonus = BonusGame(game.GetRenderer(), game.m_event, game.m_eGameState,game.GetCredit() );
	WinBonus win = WinBonus(game.GetRenderer(), game.m_event, game.m_eGameState, game.GetCredit() );
	OutroScreen outro = OutroScreen(game.GetRenderer(), &game.m_event, &game.m_eGameState);



	Music Music;
	Music.LoadMusic();

	std::cout << "Credit: " << Recovery::Read().credit << " Bet: "
		<< Recovery::Read().bet << " Win: "
		<< Recovery::Read().win << "\n";

	//Current animation frame
	int frame = 0;
	while(game.m_eGameState != QUIT)
	{

		while(SDL_PollEvent(&game.m_event) > 0)
		{


			//music.Render();
			//music.HandleEvent();
			//music.Draw();

			//usic.PlayMusic();



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

			case OUTRO:
				outro.Render();
				outro.HandleEvent();
				outro.Draw();
				outro.Delay();
				break;
			}
		} //event loop
		
	} // run loop
		
	return 0;
}
