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
#include <string>
#include <sstream>

class WinBonus: public Screen
{
	double* m_ptrCredit;
	//Texture objects
	Texture m_tBackgorund;
	Texture m_tText;

	//SDL_Event object pointer
	SDL_Event* m_event;

	//enum eGameState pointer
	eGameState* m_ptrGameState;
public:
	WinBonus(SDL_Renderer* renderer, SDL_Event& event,
			eGameState& eGameState,double* credit);

	virtual ~WinBonus();

	std::string DoubleToString(double number) const;

	virtual void Draw();
	virtual void Render();
	virtual void HandleEvent();

};

#endif /* SRC_WINBONUS_H_ */
