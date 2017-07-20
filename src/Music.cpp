/*
 * Music.cpp
 *
 *  Created on: 18.07.2017 ã.
 *      Author: Borqna
 */

#include "Music.h"

Music::Music() {
	// TODO Auto-generated constructor stub

}

Music::~Music() {
	// TODO Auto-generated destructor stub
}


void Music::setBackGroundMusic(Mix_Music* music){
	BackGroundMusic=music;
}
void Music::setChunkMusic(Mix_Chunk* chunk){
	ChunkMusic=chunk;
}
Mix_Music* Music::getBackGroundMusic(){
	return BackGroundMusic;
}
Mix_Chunk* Music::getChunkMusic(){
	return ChunkMusic;
}

void Music::LoadMusic(){

	ChunkMusic = Mix_LoadWAV("sound.wav");
	if(ChunkMusic == NULL)
	{
		cout << "Problem to Load Music" << endl;
	}
}

void Music::PlayMusic(){

	Mix_PlayChannel(-1,ChunkMusic,1);

}



