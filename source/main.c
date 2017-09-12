//#include "game_states.h"
#include "menu.h"
#include "two_player_mode.h"
#include <3ds.h>
#include <sf2d.h>
#include <sftd.h>
#include <stdio.h>
//#include <freetype.h>

int main(int argc, char **argv)
{
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));

	//sftd_init();

	hidInit();

	// Object for main menu
	Menu mainMenu;
	Menu_Init(&mainMenu);

	two_player_mode two;
	Two_Init(&two);

	Cur_State = MENU;

	bool is_Running = true;

	// Main loop
	while (is_Running)
	{
		is_Running = aptMainLoop();

		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		
		// Top screen logic
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		switch (Cur_State)
		{
		case MENU:
			Menu_Process_Upper_Screen(&mainMenu);
			break;
		case SINGLE_PLAYER:
			Menu_Process_Upper_Screen(&mainMenu);
			break;
		case TWO_PLAYER:
			Two_Process_Upper_Screen(&two);
			break;
		case GAME_OVER:
			break;
		case QUIT:
			is_Running = false;
			break;
		}
		sf2d_end_frame();
		
		// Bottom screen logic
		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		switch (Cur_State)
		{
		case MENU:
			Menu_Process_Lower_Screen(&mainMenu);
			break;
		case SINGLE_PLAYER:
			Menu_Process_Lower_Screen(&mainMenu);
			break;
		case TWO_PLAYER:
			Two_Process_Lower_Screen(&two);
			break;
		case GAME_OVER:
			break;
		case QUIT:
			is_Running = false;
			break;
		}
		sf2d_end_frame();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		sf2d_swapbuffers();
	}

	//Menu_Free(&mainMenu);

	hidExit();
	//sftd_fini();
	sf2d_fini();
	return 0;
}
