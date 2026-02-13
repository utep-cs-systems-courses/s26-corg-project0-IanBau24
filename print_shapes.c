#include <stdio.h>
#include "draw.h"

  void print_arrow(char a){
    a = 0x1E; // 30 in decimal which is >
    char b = 0xD; // 13 in decimal which is -

    // doing row major lets use read in the original orientation we get our bitmap from
    // removing 6 - row lets us  read fromt left to right instead of right to left
    for(char row = 0; row < 7; row++){ // no 90 degree rotation
      for(char col = 0; col < 5; col++){
        unsigned short colMask = 1 << (row); // no y axis mirror image
        // get bitmap fonts for dash and arrow and use colmask to compare
        unsigned short rowBitsDash = font_5x7[b][col];
        unsigned short rowBitsArrow = font_5x7[a][col];

        // to avoid double ** check if both are 1 then only put one char
        if((rowBitsDash & colMask) & (rowBitsArrow & colMask)){
          putchar('*');
        } else{
          // just evaluate each expression and print twice to keep nice formatting
          putchar((rowBitsDash & colMask) ? '*': ' ');
          putchar((rowBitsArrow & colMask)? '*' : ' ');
        }
      }
      putchar('\n');
    }
    putchar('\n');
  }

// ? Reference bitmap
// 0 0 1 0 0
// 0 1 0 1 0
// 1 0 0 0 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// { 0x04, 0x02, 0x01, 0x02, 0x04 } // 5e ^
