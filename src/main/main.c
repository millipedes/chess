#include <stdio.h>
#include "core/board/include/square.h"
#include "core/piece/include/piece.h"

int main(void) {
  piece * test_piece = init_piece(KING, WHITE);
  square * test_square = init_square(1, 3, BLACK);
  test_piece->occupation = test_square;
  debug_piece(*test_piece, 0);
  free_piece(test_piece);
  free_square(test_square);
  return 0;
}
