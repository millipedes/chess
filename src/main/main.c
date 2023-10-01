#include "core/include/game.h"

int main(void) {
  // TEST: piece/square interaction
  // piece * test_piece = init_piece(KING);
  // square * test_square = init_square(1, 3, BLACK);
  // test_piece->occupation = test_square;
  // debug_piece(test_piece, 0);
  // free_piece(test_piece);
  // free_square(test_square);

  // TEST: board allocs prints, then frees
  // board * the_board = init_board();
  // print_board(the_board);
  // free_board(the_board);

  // TEST: player allocs prints, then frees
  // player * the_player = init_player(WHITE);
  // debug_player(the_player);
  // free_player(the_player);

  // TEST: game allocs prints, then frees
  game * the_game = init_game();
  // debug_piece(the_game->players[0]->pieces[8], 0);
  move(the_game, the_game->players[0]->pieces[8], the_game->the_board->squares[4][0]);
  debug_game(the_game);
  // print_board(the_game->the_board);
  free_game(the_game);
  return 0;
}
