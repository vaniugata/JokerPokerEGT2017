/*
 * WinBonus.h
 *
 *  Created on: 14.07.2017 г.
 *      Author: Rossi
 */

#ifndef SRC_WINBONUS_H_
#define SRC_WINBONUS_H_


#include "Screen.h"
#include "Texture.h"
#include "Globals.h"
#include <fstream>
#include <string>
#include <sstream>


class WinBonus: public Screen {

	Texture m_tBackgorund;
	Texture m_tText;

	SDL_Event* m_event;

	eGameState* m_ptrGameState;

	Mix_Chunk* winning = nullptr;

public:
	WinBonus(SDL_Renderer* renderer,SDL_Event& event, eGameState& eGameState);
	virtual ~WinBonus();
	void LoadMusicFiles();

	void Draw();
	void Render();
	void HandleEvent();

	std::string DoubleToString(double number) const;

	void Close();
};

#endif /* SRC_WINBONUS_H_ */
