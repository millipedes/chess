#ifndef GAME_H
#define GAME_H

#include "core/board/include/board.h"
#include "player.h"

#define QTY_PLAYERS 2

typedef struct GAME_T {
  board * the_board;
  player * players[QTY_PLAYERS];
  uint32_t current_move;
} game;

game * init_game(void);
void debug_game(game * the_game);
void free_game(game * the_game);

#endif
