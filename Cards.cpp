

#include "Cards.h"

Cards::Cards() {
	Init();
	LoadMedia();
	for (int i = 0; i < 53; i++) {
		isClicked[i] = false;
	}
}

Cards::~Cards() {
	Close();
}

void Cards::Init() {
	m_window = SDL_CreateWindow("Press space for random rectangle",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
			WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
}

void Cards::LoadMedia() {

	SDL_Surface* loadedSurfaceBackground = IMG_Load("back.jpg");
	if (loadedSurfaceBackground == NULL) {
		cerr << "Unable to load image " << "background.jpg"
				<< "! SDL_image Error: " << IMG_GetError();
	}


	SDL_Surface* loadedSurfaceCards = IMG_Load("Deck-of-Playing-Cards2.png");
	if (loadedSurfaceCards == NULL) {
		cerr << "Unable to load image " << "Deck-of-Playing-Cards2.png"
				<< "! SDL_image Error: " << IMG_GetError();
	}

		SDL_SetColorKey(loadedSurfaceCards, SDL_TRUE,
		SDL_MapRGB(loadedSurfaceCards->format, 195, 195, 195));

	m_backgroundTexture = SDL_CreateTextureFromSurface(m_renderer,
			loadedSurfaceBackground);
	if (m_backgroundTexture == NULL) {
		cerr << "Failed to convert image surface to texture background.";
	}

	m_currentTexture = SDL_CreateTextureFromSurface(m_renderer,
			loadedSurfaceCards);
	if (m_currentTexture == NULL) {
		cerr << "Failed to convert image surface to texture2.";
	} else {
		int offsetX = CARD_WIDTH + 10;
		int offsetY = CARD_HEIGHT + 10;
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 14; col++) {

				m_gSpriteClips[col + row* 14].x = col * offsetX;
				m_gSpriteClips[col + row* 14].y = row * offsetY;
				m_gSpriteClips[col + row* 14].w = CARD_WIDTH;
				m_gSpriteClips[col + row* 14].h = CARD_HEIGHT;

				m_gSpriteCards[col][col + row* 14].x = col * offsetX;
				m_gSpriteCards[col][col + row* 14].y = row * offsetY;
				m_gSpriteCards[col][col + row* 14].w = CARD_WIDTH;
				m_gSpriteCards[col][col + row* 14].h = CARD_HEIGHT;
			}
		}
		m_BackToCard.x = 0 * CARD_WIDTH;
		m_BackToCard.y = 4 * offsetY ;
		m_BackToCard.w = CARD_WIDTH;
		m_BackToCard.h = CARD_HEIGHT;
	}

	SDL_FreeSurface(loadedSurfaceCards);
	SDL_FreeSurface(loadedSurfaceBackground);

}

void Cards::Close() {
	SDL_DestroyTexture(m_backgroundTexture);
	SDL_DestroyTexture(m_currentTexture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void Cards::render() {
	SDL_RenderCopy(m_renderer, m_backgroundTexture, NULL, NULL);
	SDL_Rect rect;
	int offsetX = 120;
	int offsetY = 250;
	rect.w = SPRITE_WIDTH;
	rect.h = SPRITE_HEIGHT;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 14; col++) {
			rect.x = offsetX + col * SPRITE_WIDTH;
			rect.y = offsetY + row * SPRITE_HEIGHT;
			if (isClicked[col + row * 13])
			{
					//int row;
					//int col;

					//for (int card = 0; card < 56; card++)
					//{
//						do
//						{
//							row = rand() % 4;
//							col = rand() % 14;
//						} while (m_gSpriteCards[row][col] != 0);
//						m_gSpriteCards[row][col] = card;
				//}
					//for (int card = 0; card < 5; card++)
					//{
						SDL_RenderCopy(m_renderer, m_currentTexture,
									&m_gSpriteClips[col + row * 13], &rect);
					//}
			}else
				SDL_RenderCopy(m_renderer, m_currentTexture, &m_BackToCard,
						&rect);
		}
	}
	SDL_RenderPresent(m_renderer);
}

void Cards::clickCard(int x, int y) {
	x -= 80;
	y -= 105;

	if (x < 13 * CARD_WIDTH && y < 4 * CARD_HEIGHT && x > 0 && y > 0) {
		int countX = 0;
		while (true) {
			x -= CARD_WIDTH;
			if (x < 0)
				break;
			else
				countX++;
		}

		int countY = 0;
		while (true) {
			y -= CARD_HEIGHT;
			if (y < 0)
				break;
			else
				countY++;
		}

		isClicked[countX + countY * 13] = true;

	}

}
