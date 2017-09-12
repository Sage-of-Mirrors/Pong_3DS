#ifndef BALL_H
#include "ball.h"
#endif // !BALL_H

#ifndef BUTTON_H
#include "button.h"
#endif // !BUTTON_H

#include "images.h"
#include "paddle.h"
#include <3ds.h>
#include <sf2d.h>
#include <sftd.h>

typedef struct
{
	sf2d_texture *midline_Tex;
	paddle player_1;
	paddle player_2;
	Ball ball;
	Button quit_Button;
	unsigned int player_1_score;
	unsigned int player_2_score;
} two_player_mode;

touchPosition touchPos;

void Two_Init(two_player_mode* two);
void Two_Process_Upper_Screen(two_player_mode* two);
void Two_Process_Lower_Screen(two_player_mode* two);
void Two_Render_Upper_Screen(two_player_mode* two);
void Two_Render_Lower_Screen(two_player_mode* two);