/*
 * WinBonus.h
 *
 *  Created on: 14.07.2017 г.
 *      Author: Rossi
 */

#ifndef SRC_WINBONUS_H_
#define SRC_WINBONUS_H_

#include "GameState.h"
#include "Texture.h"
#include "Globals.h"

class WinBonus: public GameState {
	Texture m_tBackgorund;
	SDL_Event* m_event;
	Texture m_tText;
	eGameState* m_ptrGameState;
	TTF_Font* m_font;
	Mix_Chunk* winning = nullptr;
public:
	WinBonus(SDL_Renderer* renderer,SDL_Event& event, eGameState& eGameState);
	virtual ~WinBonus();
	void LoadMusicFiles();
	void InitFont(std::string path);

	void Draw();
	void Render();
	void HandleEvent();

	void Close();
};

#endif /* SRC_WINBONUS_H_ */
