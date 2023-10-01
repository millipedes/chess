#include "include/algebraic_parsing.h"

piece_square alegraic_move_to_piece_square(game * the_game, char * move) {
  if(!move) {
    fprintf(stderr, "[ALGEBRAIC_PARSING]: Something went Wrong Parsing\n");
    return (piece_square){NULL, NULL};
  }
  if(is_pawn_move(move[0])) {
  } else if(is_knight_move(move[0])) {
  } else if(is_bishop_move(move[0])) {
  } else if(is_rook_move(move[0])) {
  } else if(is_queen_move(move[0])) {
  } else if(is_king_move(move[0])) {
  }
}

uint8_t is_pawn_move(char c) {
  // 'a' == 97 && 'h' == 104
  if(c <= 104 && c >= 97) return 1;
  return 0;
}

uint8_t is_knight_move(char c) {
  if(c == 'N') return 1;
  return 0;
}

uint8_t is_bishop_move(char c) {
  if(c == 'B') return 1;
  return 0;
}

uint8_t is_rook_move(char c) {
  if(c == 'R') return 1;
  return 0;
}

uint8_t is_queen_move(char c) {
  if(c == 'Q') return 1;
  return 0;
}

uint8_t is_king_move(char c) {
  if(c == 'K') return 1;
  return 0;
}

uint8_t is_takes(char c) {
  if(c == 'x') return 1;
  return 0;
}
