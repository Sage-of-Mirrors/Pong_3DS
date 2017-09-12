#ifndef BUTTON_H
#include "button.h"
#endif // !BUTTON_H

#include "ball.h"
#include <sf2d.h>
#include <3ds.h>

touchPosition touchPos;

typedef struct Menu
{
	sf2d_texture *game_Title_Image;
	sf2d_texture *menu_Title_Image;
	sf2d_texture *button_Selector_Image;
	Ball ball;
	Button buttons[3];
	u8 selectedButton;
} Menu;

void Menu_Init(Menu* menu);
void Menu_Process_Upper_Screen(Menu* menu);
void Menu_Render_Upper_Screen(Menu* menu);
void Menu_Process_Lower_Screen(Menu* menu);
void Menu_Render_Lower_Screen(Menu* menu);
void Menu_Free(Menu* menu);