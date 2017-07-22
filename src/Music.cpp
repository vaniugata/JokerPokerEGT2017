/*
 * Music.cpp
 *
<<<<<<< HEAD
 *  Created on: 18.07.2017 ã.
=======
 *  Created on: 18.07.2017 ï¿½.
>>>>>>> origin/master
 *      Author: Borqna
 */

#include "Music.h"

Music::Music() {
	// TODO Auto-generated constructor stub



}

Music::~Music() {

	// TODO Auto-generated destructor stub



	Mix_FreeChunk(ChunkMusic);
	ChunkMusic = nullptr;

}


void Music::setChunkMusic(Mix_Chunk* chunk){
	ChunkMusic=chunk;
}

Mix_Chunk* Music::getChunkMusic(){
	return ChunkMusic;
}
void Music::LoadMusic(){

	ChunkMusic = Mix_LoadWAV("ResourcesMusic/fonMusic.wav");

	if(ChunkMusic==NULL){

		std::cerr<<" Problem to load "<<std::endl;
	}
}
void Music::PlayMusic(){

	Mix_PlayChannel(0,ChunkMusic,0);

}
<<<<<<< HEAD
//void Music::Screen()
=======
void Music::Screen()
>>>>>>> origin/master


