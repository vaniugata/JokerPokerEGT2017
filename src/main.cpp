#include "Game.h"
#include "Globals.h"
#include "Texture.h"
#include "IntroScreen.h"
#include "Deck.h"
#include "OutroScreen.h"
#include "Music.h"
#include "Recovery.h"

int main(int args, char* argc[])
{
	Game game;
	IntroScreen intro = IntroScreen(game.GetRenderer(), game.m_event,
		game.m_eGameState, game.GetCredit(), game.GetBet());
	BonusGame bonus = BonusGame(game.GetRenderer(), game.m_event, game.m_eGameState, game.GetCredit());
	WinBonus win = WinBonus(game.GetRenderer(), game.m_event, game.m_eGameState, game.GetCredit());
	OutroScreen outro = OutroScreen(game.GetRenderer(), &game.m_event, &game.m_eGameState);

	Music::LoadMusic();
	Mix_PlayMusic(Music::getBackgraund(), -1);

	while(game.m_eGameState != QUIT)
	{
		switch(game.m_eGameState)
		{
		case INTRO:
			intro.Render();
			break;
		case PLAY:
			game.Render();
			break;
		case BONUS:
			bonus.Render();
			break;
		case WIN:
			win.Render();
			break;
		case OUTRO:
			outro.Render();
			break;
		}
		game.Draw();

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

			case OUTRO:
				outro.Render();
				outro.HandleEvent();
				outro.Draw();
				outro.Delay();
				break;
			}
		} //event lop
	} // run loop

	Music::Free();

	return 0;
}
