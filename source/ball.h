#pragma once
#define BALL_H
#include <sf2d.h>

typedef struct Ball
{
	signed int xPos;
	signed int yPos;
	signed int xVelocity;
	signed int yVelocity;
	sf2d_texture *ball_Image;
} Ball;

void Ball_init(Ball* ball);
void Ball_render(Ball* ball);
void Ball_process_title(Ball* ball);
void Ball_process_game(Ball* ball);
void Ball_Check_Collide(Ball* ball, int xPos, int yPos, sf2d_texture *tex);
bool Ball_check_hit_screen_left(Ball* ball);
bool Ball_check_hit_screen_right(Ball* ball);
bool Ball_check_hit_screen_top_bottom(Ball* ball);
bool Ball_check_hit_image_left_right(Ball* ball, int xPos, int yPos, sf2d_texture *tex);
bool Ball_check_hit_image_top_bottom(Ball* ball, int xPos, int yPos, sf2d_texture *tex);
bool Ball_check_hit_paddle(Ball* ball); // Remember to add Paddle* pad!