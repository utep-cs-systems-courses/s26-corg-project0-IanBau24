#ifndef DRAW_INCLUDED
#define DRAW_INCLUDED

void print_triangle(int startCol, int size);
void print_square(int startCol, int size);
void print_char_5x7(char c);
void print_arrow(char c);
void print_char_8x12(char c);
void print_char_11x16(char c);

extern const unsigned char font_5x7[][5];
extern const unsigned char font_8x12[][12]; // add 8 by 12 font
extern const unsigned char font_11x16[][11];

#endif
