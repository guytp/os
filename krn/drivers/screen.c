#include "screen.h"
#include "io.h"

int screenBufferLocation = 0;

void screen_setup() {
  screen_clear();
}

byte screen_get_buffer_x() {
    return screenBufferLocation - (screen_get_buffer_y() * TEXTMODE_COLS);
}

byte screen_get_buffer_y() {
    return screenBufferLocation / TEXTMODE_COLS;
}

void screen_clear() {
    int screenSize = TEXTMODE_ROWS * TEXTMODE_COLS;
    int i;
    char *c = (char*)VIDEO_ADDRESS;

    for (i = 0; i < screenSize * 2; i += 2) {
        c[i] = ' ';
        c[i + 1] = WHITE_ON_BLUE;
    }

    screen_cursor_set_location(0, 0);
}

void screen_cursor_set_location(byte x, byte y) {
    screenBufferLocation = (y * TEXTMODE_COLS + x);
    screen_cursor_move_to_offset();
}

void screen_cursor_move_to_offset() {
    int offset = screenBufferLocation;
    io_out_byte(SCREEN_REGISTER_CONTROL, 14);
    io_out_byte(SCREEN_REGISTER_DATA, offset >> 8);
    io_out_byte(SCREEN_REGISTER_CONTROL, 15);
    io_out_byte(SCREEN_REGISTER_DATA, offset);
}

void screen_scroll() {
    char *buff = (char*)VIDEO_ADDRESS;
    int i = TEXTMODE_COLS + 1;
    for (i; i < VIDEO_BUFFER_SIZE; i++) {
        buff[(i  - TEXTMODE_COLS) * 2] = buff[i * 2];
    }
    for (i = 0; i < TEXTMODE_COLS; i+=2) {
        buff[i] = ' ';
    }
    screenBufferLocation -= TEXTMODE_COLS;
}

void screen_print(char * text) {
    int i = 0;
    char c = text[i];
    char *buff = (char*)VIDEO_ADDRESS;
    while (c != '\0') {
        if (c == '\n') {
            byte y = screen_get_buffer_y();
            screen_cursor_set_location(0, y + 1);
        }
        else if (c == '\r') {
            // Do nothing
        }
        else {
            if (screenBufferLocation * 2 == VIDEO_BUFFER_SIZE) {
                screen_scroll();
            }
            buff[screenBufferLocation * 2] = c;
            screenBufferLocation++;
        }
        i++;
        c = text[i];
    }
    screen_cursor_move_to_offset();
}