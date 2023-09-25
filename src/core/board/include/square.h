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
  uint8_t rank;
  uint8_t file;
} square;

square * init_square(uint8_t rank, uint8_t file, color_attribute color);
void debug_square(square * the_square, uint8_t called);
uint8_t rank_to_algebraic(uint8_t rank);
char file_to_algebraic(uint8_t file);
void free_square(square * the_square);

#endif
