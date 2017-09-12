#include "paddle.h"
#include "images.h"
#include <3ds.h>

void paddle_init(paddle* pad, int x, int y, u16 keyUp, u16 keyDown)
{
	pad->paddle_Image = sf2d_create_texture_mem_RGBA8(paddle_tex.pixel_data, paddle_tex.width, paddle_tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	pad->xPos = x;
	pad->yPos = y;
	pad->up_key = keyUp;
	pad->down_key = keyDown;
}

void paddle_process(paddle* pad)
{
	u32 kHeld = hidKeysHeld();

	if (!(pad->yPos <= 0))
	{
		if (kHeld & pad->up_key)
		{
			pad->yPos -= 6;
			if (pad->yPos < 0)
				pad->yPos = 0;
		}
	}

	if (!(pad->yPos >= 210))
	{
		if (kHeld & pad->down_key)
		{
			pad->yPos += 6;
			if (pad->yPos > 210)
				pad->yPos = 210;
		}
	}
}

bool paddle_check_on_screen(paddle* pad)
{
	if (pad->yPos > -1 && pad->yPos < 210)
		return true;
	else
		return false;
}