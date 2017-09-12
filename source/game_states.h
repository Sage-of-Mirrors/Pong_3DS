#define GAME_STATES_H

typedef enum
{
	MENU,
	SINGLE_PLAYER,
	TWO_PLAYER,
	GAME_OVER,
	QUIT
} game_states;

game_states Cur_State;