/*
 * Music.cpp
 *
 *  Created on: 18.07.2017 �.
 *      Author: Borqna
 */

#include "Music.h"

Music::Music() {
	// TODO Auto-generated constructor stub

}

Music::~Music() {
	Mix_FreeMusic(BackGroundMusic);
	BackGroundMusic = nullptr;

	Mix_FreeChunk(ChunkMusic);
	ChunkMusic = nullptr;
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

void Music::LoadMusic(std::string path){

	ChunkMusic = Mix_LoadWAV(path.c_str());
	if(ChunkMusic == NULL)
	{
		std::cout << "Problem to Load Music" << std::endl;
	}
}

void Music::PlayMusic(){

	Mix_PlayChannel(-1,ChunkMusic,1);

}



