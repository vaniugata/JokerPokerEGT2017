/*
 * Music.h
 *
 *  Created on: 18.07.2017 ã.
 *      Author: Borqna
 */

#ifndef SRC_MUSIC_H_
#define SRC_MUSIC_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include<iostream>
using namespace std;

class Music {
public:
	Music();
	virtual ~Music();

	void setBackGroundMusic(Mix_Music* music);
	void setChunkMusic(Mix_Chunk* chunk);

	Mix_Music* getBackGroundMusic();
	Mix_Chunk* getChunkMusic();

	void LoadMusic();

	void PlayMusic();

private:

	Mix_Music* BackGroundMusic = NULL;
	Mix_Chunk* ChunkMusic = NULL;
};

#endif /* SRC_MUSIC_H_ */
