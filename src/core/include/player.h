#ifndef PLAYER_H
#define PLAYER_H

#include "core/piece/include/piece.h"

#define QTY_PIECES 16

#define KING_INDEX 0
#define QUEEN_INDEX 1
#define ROOK_ONE_INDEX 2
#define ROOK_TWO_INDEX 3
#define BISHOP_ONE_INDEX 4
#define BISHOP_TWO_INDEX 5
#define KNIGHT_ONE_INDEX 6
#define KNIGHT_TWO_INDEX 7

typedef struct PLAYER_T {
  piece ** pieces;
  color_attribute color;
} player;

player * init_player(color_attribute color);
void debug_player(player * the_player);
void free_player(player * the_player);

#endif
