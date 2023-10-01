#ifndef ALGEBRAIC_PARSING_H
#define ALGEBRAIC_PARSING_H

#include "core/include/game.h"

typedef struct PIECE_SQUARE_T {
  piece * the_piece;
  square * the_square;
} piece_square;

piece_square alegraic_move_to_piece_square(game * the_board, char * move);
uint8_t is_pawn_move(char c);
uint8_t is_knight_move(char c);
uint8_t is_bishop_move(char c);
uint8_t is_rook_move(char c);
uint8_t is_queen_move(char c);
uint8_t is_king_move(char c);
uint8_t is_takes(char c);

#endif
