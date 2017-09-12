#include "two_player_mode.h"

void Two_Init(two_player_mode* two)
{
	two->midline_Tex = sf2d_create_texture_mem_RGBA8(midline_Tex.pixel_data, midline_Tex.width, midline_Tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	paddle_init(&two->player_1, 30, 42, KEY_DUP, KEY_DDOWN);
	paddle_init(&two->player_2, 370, 42, KEY_X, KEY_B);
	Ball_init(&two->ball);
	Button_Init(&two->quit_Button, sf2d_create_texture_mem_RGBA8(quit_Button_Tex.pixel_data, quit_Button_Tex.width, quit_Button_Tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM), 96, 181, Button_Action_Menu);
	two->player_1_score = 0;
	two->player_2_score = 0;
}

void Two_Process_Upper_Screen(two_player_mode* two)
{
	Ball_Check_Collide(&two->ball, two->player_1.xPos, two->player_1.yPos, two->player_1.paddle_Image);
	Ball_Check_Collide(&two->ball, two->player_2.xPos, two->player_2.yPos, two->player_2.paddle_Image);
	Ball_process_game(&two->ball);
	paddle_process(&two->player_1);
	paddle_process(&two->player_2);

	Two_Render_Upper_Screen(two);
}

void Two_Process_Lower_Screen(two_player_mode* two)
{
	hidTouchRead(&touchPos);

	if (Button_Check_Press(touchPos, &two->quit_Button))
	{
		two->quit_Button.button_Action();
	}

	Two_Render_Lower_Screen(two);
}

void Two_Render_Upper_Screen(two_player_mode* two)
{
	sf2d_draw_texture(two->midline_Tex, 196, 0);
	sf2d_draw_texture(two->player_1.paddle_Image, two->player_1.xPos, two->player_1.yPos);
	sf2d_draw_texture(two->player_2.paddle_Image, two->player_2.xPos, two->player_2.yPos);
}

void Two_Render_Lower_Screen(two_player_mode* two)
{
	sf2d_draw_texture(two->quit_Button.button_Image, two->quit_Button.xPos, two->quit_Button.yPos);
}