#ifndef TYPES_HEADER
#define TYPES_HEADER
#include "../kernel.h"
#define TEXTMODE_ROWS 25
#define TEXTMODE_COLS 80
#define WHITE_ON_BLUE 0x3F
#define VIDEO_ADDRESS 0x0B8000
#define VIDEO_BUFFER_SIZE (TEXTMODE_ROWS * TEXTMODE_COLS * 2)
#define SCREEN_REGISTER_CONTROL 0x03D4
#define SCREEN_REGISTER_DATA  0x03D5

void screen_setup();
void screen_clear();
byte screen_get_buffer_x();
byte screen_get_buffer_y();
void screen_scroll();
void screen_cursor_set_location(byte x, byte y);
void screen_cursor_move_to_offset();
void screen_print(char * text);
#endif