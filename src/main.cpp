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

	//animation test================================================
	int frame = 0;
	SDL_Surface* s = IMG_Load("Resources/betButtons.png");
	SDL_Texture* t = SDL_CreateTextureFromSurface(game.GetRenderer(),s);
	int width = s->w, height = s->h;

	const int animationFrames = 4;
	SDL_Rect animation[animationFrames]
	{
		{0,0, width / 2, height / 2},
		{width / 2, 0, width / 2, height / 2},
		{ 0, height / 2, width / 2, height / 2 },
		{ width / 2, height / 2, width / 2, height / 2 }
	};

	SDL_Rect dest{ 400,300, 150, 150 };
	//animation test================================================


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
				//game.Render();
				//game.RenderBonusGame();
				game.HandleEvent();
			//	game.Draw();
				break;
			}
		} //event loop
		
		game.Render();

		++frame;
		
		if(frame / (8* animationFrames) == animationFrames)
		{
			frame = 0;
		}
		SDL_RenderCopy(game.GetRenderer(), t, &animation[frame / (8 * animationFrames)], &dest);

		game.Draw();
	} // run loop
		
	
	return 0;
}