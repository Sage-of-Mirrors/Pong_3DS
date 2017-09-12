#include "menu.h"
#include "images.h"
#include <3ds.h>

void Menu_Init(Menu *menu)
{
	menu->menu_Title_Image = sf2d_create_texture_mem_RGBA8(menu_Title_Tex.pixel_data, menu_Title_Tex.width, menu_Title_Tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	menu->button_Selector_Image = sf2d_create_texture_mem_RGBA8(button_Selector_Tex.pixel_data, button_Selector_Tex.width, button_Selector_Tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	menu->game_Title_Image = sf2d_create_texture_mem_RGBA8(game_title_tex.pixel_data, game_title_tex.width, game_title_tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	Ball_init(&menu->ball);
	Button_Init(&menu->buttons[0], sf2d_create_texture_mem_RGBA8(single_Button_Tex.pixel_data, quit_Button_Tex.width, quit_Button_Tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM), 96, 53, Button_Action_1_Player);
	Button_Init(&menu->buttons[1], sf2d_create_texture_mem_RGBA8(double_Button_Tex.pixel_data, quit_Button_Tex.width, quit_Button_Tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM), 96, 117, Button_Action_2_Players);
	Button_Init(&menu->buttons[2], sf2d_create_texture_mem_RGBA8(quit_Button_Tex.pixel_data, quit_Button_Tex.width, quit_Button_Tex.height, TEXFMT_RGBA8, SF2D_PLACE_RAM), 96, 181, Button_Action_Quit);

	menu->selectedButton = 0;
}

void Menu_Process_Upper_Screen(Menu* menu)
{
	Ball_process_title(&menu->ball);

	Ball_Check_Collide(&menu->ball, 93, 93, menu->game_Title_Image);

	Menu_Render_Upper_Screen(menu);
}

void Menu_Render_Upper_Screen(Menu* menu)
{
	sf2d_draw_texture(menu->game_Title_Image, 93, 93);
}

void Menu_Process_Lower_Screen(Menu* menu)
{
	hidTouchRead(&touchPos);

	u32 kDown = hidKeysDown();

	if (kDown & KEY_A)
		menu->buttons[menu->selectedButton].button_Action();
	if (kDown & KEY_DUP)
	{
		if (menu->selectedButton > 0)
			menu->selectedButton--;
	}
	if (kDown & KEY_DDOWN)
	{
		if (menu->selectedButton < 2)
			menu->selectedButton++;
	}

	for (int i = 0; i < 3; i++)
	{
		if (Button_Check_Press(touchPos, &menu->buttons[i]))
		{
			menu->selectedButton = i;
			menu->buttons[i].button_Action();
		}
	}

	Menu_Render_Lower_Screen(menu);
}

void Menu_Render_Lower_Screen(Menu* menu)
{
	sf2d_draw_texture(menu->menu_Title_Image, 0, 0);

	for (int i = 0; i < 3; i++)
	{
		sf2d_draw_texture(menu->buttons[i].button_Image, menu->buttons[i].xPos, menu->buttons[i].yPos);
	}

	sf2d_draw_texture(menu->button_Selector_Image, menu->buttons[menu->selectedButton].xPos - 48, menu->buttons[menu->selectedButton].yPos + 8);
}

void Menu_Free(Menu* menu)
{

}