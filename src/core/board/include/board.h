#ifndef BOARD_H
#define BOARD_H

#include "main/include/constants_macros.h"
#include "core/piece/include/piece.h"
#include "square.h"

typedef struct BOARD_T {
  square * squares[FILES][RANKS];
} board;

board * init_board(void);
void print_board(board * the_board);
void print_board_color(color_attribute color);
void free_board(board * the_board);

#endif
