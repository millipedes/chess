#ifndef PIECE_TYPE_H
#define PIECE_TYPE_H

#include <stdlib.h>

typedef enum {
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN,
} piece_type;

const char * piece_type_to_string(piece_type type);
char piece_type_to_char(piece_type type);

#endif
