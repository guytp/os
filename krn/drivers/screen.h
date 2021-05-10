#ifndef SCREEN_HEADER
#define SCREEN_HEADER
#include "../kernel.h"

#define TEXTMODE_ROWS 25
#define TEXTMODE_COLS 80
#define VIDEO_ADDRESS 0x0B8000
#define VIDEO_BUFFER_SIZE (TEXTMODE_ROWS * TEXTMODE_COLS * 2)
#define SCREEN_REGISTER_CONTROL 0x03D4
#define SCREEN_REGISTER_DATA  0x03D5

typedef enum {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    Pink = 13,
    Yellow = 14,
    White = 15,
}  TextModeColour;

void screen_setup();
void screen_clear();
void screen_text_style(TextModeColour foreground, TextModeColour background);
byte screen_get_buffer_x();
byte screen_get_buffer_y();
void screen_scroll();
void screen_cursor_set_location(byte x, byte y);
void screen_cursor_move_to_offset();
void screen_print(char * text);
#endif