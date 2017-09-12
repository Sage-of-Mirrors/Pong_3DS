#include "ball.h"
#include "images.h"
#include <stdlib.h>

void Ball_init(Ball* ball)
{
	ball->xPos = 40;
	ball->yPos = 20;
	ball->xVelocity = 6;
	ball->yVelocity = 4;
	ball->ball_Image = sf2d_create_texture_mem_RGBA8(ball_tex.pixel_data, ball_tex.width, ball_tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
}

void Ball_render(Ball* ball)
{
	sf2d_draw_texture(ball->ball_Image, ball->xPos, ball->yPos);
}

void Ball_process_title(Ball* ball)
{
	if (Ball_check_hit_screen_top_bottom(ball))
		ball->yVelocity = -ball->yVelocity;
	if (Ball_check_hit_screen_left(ball) || Ball_check_hit_screen_right(ball))
		ball->xVelocity = -ball->xVelocity;

	ball->xPos += ball->xVelocity;
	ball->yPos += ball->yVelocity;

	Ball_render(ball);
}

void Ball_process_game(Ball* ball)
{
	if (Ball_check_hit_screen_top_bottom(ball))
		ball->yVelocity = -ball->yVelocity;
	if (Ball_check_hit_screen_left(ball) || Ball_check_hit_screen_right(ball))
		ball->xVelocity = -ball->xVelocity;

	ball->xPos += ball->xVelocity;
	ball->yPos += ball->yVelocity;

	Ball_render(ball);
}

bool Ball_check_hit_screen_top_bottom(Ball* ball)
{
	if (ball->yPos < -1 || ball->yPos > 232)
		return true;
	else
		return false;
}

bool Ball_check_hit_screen_left(Ball* ball)
{
	if (ball->xPos < -1)
		return true;
	else
		return false;
}

bool Ball_check_hit_screen_right(Ball* ball)
{
	if (ball->xPos > 392)
		return true;
	else
		return false;
}

bool Ball_check_hit_image_left_right(Ball* ball, int xPos, int yPos, sf2d_texture *tex)
{
	return false;
}

bool Ball_check_hit_image_top_bottom(Ball* ball, int xPos, int yPos, sf2d_texture *tex)
{
	return false;
}

void Ball_Check_Collide(Ball* ball, int xPos, int yPos, sf2d_texture *tex)
{
	float w = 0.5 * (8 + tex->width);
	float h = 0.5 * (8 + tex->height);

	float ballCenterX = (ball->xPos + ball->xPos + 8) / 2;
	float ballCenterY = (ball->yPos + ball->yPos + 8) / 2;

	float texCenterX = (xPos + xPos + tex->width) / 2;
	float texCenterY = (yPos + yPos + tex->height) / 2;

	float dX = ballCenterX - texCenterX;
	float dY = ballCenterY - texCenterY;

	if (abs(dX) <= w && abs(dY) <= h)
	{
		float wy = w * dY;
		float hx = h * dX;

		if (wy > hx)
		{
			if (wy > -hx)
			{
				/* collision at the top */
				ball->yVelocity = -ball->yVelocity;
				ball->yPos += (yPos - (ball->yPos + 8));
			}
			else
			{
				/* on the left */
				ball->xVelocity = -ball->xVelocity;
				ball->xPos += ((ball->xPos + 8) - (xPos));
			}
		}

		else
		{
			if (wy > -hx)
			{
				/* on the right */
				ball->xVelocity = -ball->xVelocity;
				ball->xPos += (ball->xPos - (xPos + tex->width));
			}

			else
			{
				/* at the bottom */
				ball->yVelocity = -ball->yVelocity;
				ball->yPos += (ball->yPos - (yPos + tex->height));
			}
		}
	}
}