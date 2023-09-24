#ifndef PLAYER_H
#define PLAYER_H

#include "core/include/color_attribute.h"
#include "core/piece/include/piece.h"

#define QTY_PIECES 16

typedef struct PLAYER_T {
  piece ** pieces;
  color_attribute color;
} player;

player * init_player(color_attribute color);
void debug_player(player * the_player);
void free_player(player * the_player);

#endif
