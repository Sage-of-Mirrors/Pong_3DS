#include <3ds.h>
#include <sf2d.h>

typedef struct
{
	sf2d_texture *paddle_Image;
	signed int xPos;
	signed int yPos;
	u16 up_key;
	u16 down_key;
} paddle;

void paddle_init(paddle* pad, int x, int y, u16 keyUp, u16 keyDown);
void paddle_process(paddle* pad);
bool paddle_check_on_screen(paddle* pad);