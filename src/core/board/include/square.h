#ifndef SQUARE_H
#define SQUARE_H

#include <stdio.h>
#include <stdint.h>

#include "core/include/color_attribute.h"

// Forward declaration from src/core/piece/include/piece.h
typedef struct PIECE_T piece;
extern void debug_piece(piece * the_piece, uint8_t called);

typedef struct SQUARE_T {
  piece * occupation;
  color_attribute color;
  short rank;
  short file;
} square;

square * init_square(short rank, short file, color_attribute color);
void debug_square(square * the_square, uint8_t called);
short rank_to_algebraic(short rank);
char file_to_algebraic(short file);
void free_square(square * the_square);

#endif
