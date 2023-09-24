#include <stdio.h>
#include "core/board/include/board.h"
#include "core/include/player.h"

int main(void) {
  // TEST: piece/square interaction
  piece * test_piece = init_piece(KING);
  square * test_square = init_square(1, 3, BLACK);
  test_piece->occupation = test_square;
  debug_piece(test_piece, 0);
  free_piece(test_piece);
  free_square(test_square);

  // TEST: board allocs prints, then frees
  board * the_board = init_board();
  print_board(the_board);
  free_board(the_board);

  // TEST: player allocs prints, then frees
  player * the_player = init_player(WHITE);
  debug_player(the_player);
  free_player(the_player);
  return 0;
}
