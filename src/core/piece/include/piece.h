#ifndef PIECE_H
#define PIECE_H

#include <stdio.h>
#include <stdint.h>

#include "core/include/color_attribute.h"
#include "piece_type.h"

// Forward declaration from src/core/board/include/square.h
typedef struct SQUARE_T square;
extern void debug_square(square * the_square, uint8_t called);

typedef struct PIECE_T {
  square * occupation;
  piece_type type;
  color_attribute color;
  uint8_t has_moved;
} piece;

piece * init_piece(piece_type type, color_attribute color);

uint8_t is_move_valid(piece * the_piece, square * the_square);
uint8_t is_king_move_valid(piece * the_piece, square * the_square);
uint8_t is_queen_move_valid(piece * the_piece, square * the_square);
uint8_t is_rook_move_valid(piece * the_piece, square * the_square);
uint8_t is_bishop_move_valid(piece * the_piece, square * the_square);
uint8_t is_knight_move_valid(piece * the_piece, square * the_square);
uint8_t is_pawn_move_valid(piece * the_piece, square * the_square);

void debug_piece(piece * the_piece, uint8_t called);
void free_piece(piece * the_piece);

#endif
