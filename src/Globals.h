#ifndef GLOBALS_H
#define GLOBALS_H

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 680;

const double DENOM = 5.00;

//----PAYTABLE-----------------------------------------------------------------
const double PAYTABLE_TEXTURE_SCALE_FACTOR = 0.75;

const int TEXT_BLANK_SPACE = 250;

const int X_BORDER_OFFSET = 25;
const int Y_BORDER_OFFSET = 10;

const int T_BTN_W_BET = 480;
const int T_BTN_H_BET = 443;

const int S_BETBTN_W = 100;
const int S_BETBTN_H = 100;

//----INTRO--------------------------------------------------------------------
const int INTRO_BTN_W = 214;
const int INTRO_BTN_H = 53;

//----DECK---------------------------------------------------------------------
const int NUM_OF_CARDS = 54;

const int T_CARD_COLS = 13;
const int T_CARD_ROWS = 4;

const int T_CARD_WIDTH = 243;
const int T_CARD_HEIGHT = 168;

const int ENUM_COUNTS_VALUE = 13;
const int ENUM_COUNTS_SUIT = 4;

const int HOLD_W = 168;
const int HOLD_H = 486;//316
//----BONUS--------------------------------------------------------------------
const int S_BONUSBTN_W = 204;
const int S_BONUSBTN_H = 104;

typedef enum
{
	INTRO,
	PLAY,
	BONUS,
	WIN,
	OUTRO,
	QUIT
} eGameState;

#endif
