#ifndef BUTTON_H
#define BUTTON_H
#endif // !BUTTON_H

#ifndef GAME_STATES_H
#include "game_states.h"
#endif // !GAME_STATES_H#include "game_states.h"
#include <sf2d.h>
#include <3ds.h>

typedef void (*button_action_cb)();

typedef struct
{
	unsigned int xPos;
	unsigned int yPos;
	unsigned int width;
	unsigned int height;
	sf2d_texture *button_Image; // Image of the button
	button_action_cb button_Action; // Function to call when the button is pressed
} Button;

void Button_Init(Button* button, sf2d_texture *tex, int xPos, int yPos, button_action_cb action);
bool Button_Check_Press(touchPosition touch, Button* button);
void Button_Action_1_Player();
void Button_Action_2_Players();
void Button_Action_Menu();
void Button_Action_Quit();