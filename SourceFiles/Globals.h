#ifndef GLOBALS_H
#define GLOBALS_H

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 680;

const double PAYTABLE_TEXTURE_SCALE_FACTOR = 0.75;

const int TEXT_BLANK_SPACE = 250;

typedef enum
{
	INTRO,
	PLAY,
	OUTRO,
	QUIT,
} eGameState;

#endif