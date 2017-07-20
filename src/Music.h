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
#include "includesSDL2.h"
#include<iostream>
#include <string>



class Music {
public:
	Music();
	virtual ~Music();

	void setBackGroundMusic(Mix_Music* music);
	void setChunkMusic(Mix_Chunk* chunk);

	Mix_Music* getBackGroundMusic();
	Mix_Chunk* getChunkMusic();

	void LoadMusic(std::string path);


	void PlayMusic();

private:

	Mix_Music* BackGroundMusic = NULL;
	Mix_Chunk* ChunkMusic = NULL;
};

#endif /* SRC_MUSIC_H_ */
