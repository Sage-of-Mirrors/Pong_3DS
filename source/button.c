#include "button.h"
#include <3ds.h>

void Button_Init(Button* button, sf2d_texture *tex, int xPos, int yPos, button_action_cb action)
{
	button->button_Image = tex;
	button->xPos = xPos;
	button->yPos = yPos;
	button->width = tex->width;
	button->height = tex->height;
	button->button_Action = action;
}

bool Button_Check_Press(touchPosition touch, Button* button)
{
	int touchX = touch.px;
	int touchY = touch.py;
	u32 kDown = hidKeysDown();

	if (kDown & KEY_TOUCH && touchX > button->xPos && touchX < button->xPos + button->width && touchY > button->yPos && touchY < button->yPos + button->height)
	{
		return true;
	}

	else
		return false;
}

void Button_Action_1_Player()
{
	Cur_State = SINGLE_PLAYER;
}

void Button_Action_2_Players()
{
	Cur_State = TWO_PLAYER;
}

void Button_Action_Menu()
{
	Cur_State = MENU;
}

void Button_Action_Quit()
{
	Cur_State = QUIT;
}