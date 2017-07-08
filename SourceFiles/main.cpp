#include "Game.h"
#include "Globals.h"
#include "Texture.h"
#include "GameObject.h"
#include "PaytableObject.h"

int main(int args, char* argc[])
{
	Game game;

	while(game.m_eGameState != QUIT)
	{
		game.Update();

 		while(SDL_PollEvent(&game.m_event) > 0)
		{
 			switch(game.m_event.type)
			{
			case SDL_QUIT:
				game.SetGameState(QUIT);
				break;

			case SDL_KEYDOWN:
				game.ProcessInput();
				break;
			}
				

			
		}	
		game.RenderScreen();
	}
		
	
	return 0;
}