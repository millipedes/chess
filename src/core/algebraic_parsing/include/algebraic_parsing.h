#ifndef ALGEBRAIC_PARSING_H
#define ALGEBRAIC_PARSING_H

#include "core/board/include/board.h"

typedef struct PIECE_SQUARE_T {
  piece * the_piece;
  square * the_square;
} piece_square;

piece_square alegraic_move_to_piece_square(char * move);

#endif
