#ifndef PIECE_H
#define PIECE_H

#include <stdio.h>
#include <stdint.h>

#include "piece_type.h"

// Forward declaration from src/core/board/include/square.h
typedef struct SQUARE_T square;
extern void debug_square(square * the_square, uint8_t called);

typedef struct PIECE_T {
  square * occupation;
  piece_type type;
  uint8_t has_moved;
} piece;

piece * init_piece(piece_type type);
void debug_piece(piece * the_piece, uint8_t called);
void free_piece(piece * the_piece);

#endif
