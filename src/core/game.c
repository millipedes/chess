#include "include/game.h"

game * init_game(void) {
  game * the_game = calloc(1, sizeof(struct GAME_T));
  the_game->the_board = init_board();
  the_game->players[0] = init_player(WHITE);
  the_game->players[1] = init_player(BLACK);
  the_game->current_move = 0;
  return the_game;
}

void debug_game(game * the_game) {
  printf("[GAME]: move no. %u\n", the_game->current_move);
  print_board(the_game->the_board);
  debug_player(the_game->players[0]);
  debug_player(the_game->players[1]);
}

void free_game(game * the_game) {
  if(the_game) {
    if(the_game->the_board)
      free_board(the_game->the_board);
    if(the_game->players[0])
      free_player(the_game->players[0]);
    if(the_game->players[1])
      free_player(the_game->players[1]);
    free(the_game);
  }
}
