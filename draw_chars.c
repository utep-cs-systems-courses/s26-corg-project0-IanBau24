#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_5x7(char c)
{
  c -= 0x20;
  for (char col = 0; col < 5; col++) {
    for (char row = 0; row < 7; row++) {
      unsigned short rowBits = font_5x7[c][col];
      unsigned short colMask = 1 << (6-row); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

void print_char_8x12(char c){
  c -= 0x20;
  // this is row major so we traverse one bit of each col per row
  // then row increases and we traverse the adjacent bit of each col
  // ex: for char a at row = 0 col = 0
  // we check bit 7 of each
  /*00  → 0
    00  → 0
    76  → 0
    DC  → 1
    CC  → 1
    7C  → 0
    0C  → 0
    78  → 0
    00  → 0
    00  → 0
    00  → 0
    00  → 0 */

  for(char row = 0; row < 8; row++){ 
    for(char col = 0; col < 12; col++){ 
      unsigned short colMask = 1 << (7 - row); // mirror image across y axis, vertical flip

      /*reading from the last element does a horizontal flip allowing us to get
       the same orientation as original print chars*/
      unsigned short rowBits = font_8x12[c][11 - col];
      putchar((rowBits & colMask) ? '*':' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

