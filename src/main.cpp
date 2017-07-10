#include "Game.h"
#include "Globals.h"
#include "Texture.h"

int main(int args, char* argc[])
{
	Game game;

	while(game.m_eGameState != QUIT)
	{
		game.Render();

 		while(SDL_PollEvent(&game.m_event) > 0)
		{
 			switch(game.m_event.type)
			{
			case SDL_QUIT:
				game.SetGameState(QUIT);
				break;

			case SDL_KEYDOWN:
				game.ProcessKeyInput();
				break;

			case SDL_MOUSEBUTTONDOWN:
				game.ProcessMouseInput();
				break;
			}
		} //event loop	
		game.Draw();
	} // run loop
		
	
	return 0;
}