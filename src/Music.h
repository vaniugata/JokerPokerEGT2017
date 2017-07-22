/*
 * Music.h
 *
<<<<<<< HEAD
 *  Created on: 18.07.2017 ã.
=======
 *  Created on: 18.07.2017 ï¿½.
>>>>>>> origin/master
 *      Author: Borqna
 */

#ifndef SRC_MUSIC_H_
#define SRC_MUSIC_H_
using namespace std;
#include"Screen.h"
#include "includesSDL2.h"
#include<iostream>
#include <string>



class Music
{


public:
	Music();
	virtual ~Music();

	void setChunkMusic(Mix_Chunk* chunk);

	Mix_Chunk* getChunkMusic();



    void LoadMusic();
	void PlayMusic();
	void Press();
	void Release();
	void IsPressed();

private:

    bool m_buttonIsPressed;

    SDL_Texture* m_TextureTPressed;

    SDL_Texture* m_TextureButton;

	Mix_Chunk* ChunkMusic = NULL;
};

#endif /* SRC_MUSIC_H_ */
