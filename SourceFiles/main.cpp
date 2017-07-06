#include "Game.h"

int main(int args, char* argc[])
{
	Game* game = new Game();

	SDL_Rect dest{ 100, 100, 300, 300 };
	while(game->m_eGameState != QUIT)
	{
		game->GetTexture()->Render(*game->GetRenderer(), \
			game->GetTexture()->m_rectSource, dest);

		SDL_RenderPresent(game->GetRenderer() );
		while(SDL_PollEvent(&game->m_event) > 0)
		{
			switch(game->m_event.type)
			{
			case SDL_QUIT:
				game->m_eGameState = QUIT;
				break;
			}
		}
	}
	
	delete game;

	return 0;
}