#ifndef PIECE_H
#define PIECE_H

#include <stdio.h>
#include <stdint.h>

#include "core/include/color_attribute.h"
#include "piece_type.h"

// Forward declaration from src/core/board/include/square.h
typedef struct SQUARE_T square;
extern void debug_square(square the_square, uint8_t called);

typedef struct PIECE_T {
  square * occupation;
  piece_type type;
  color_attribute color;
} piece;

void debug_piece(piece the_piece, uint8_t called);

#endif
