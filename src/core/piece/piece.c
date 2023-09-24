#include "include/piece.h"
#include "core/board/include/square.h"

piece * init_piece(piece_type type) {
  piece * the_piece = calloc(1, sizeof(struct PIECE_T));
  the_piece->type = type;
  the_piece->occupation = NULL;
  the_piece->has_moved = 0;
  return the_piece;
}

void debug_piece(piece * the_piece, uint8_t called) {
  printf("[PIECE]: %s, ", piece_type_to_string(the_piece->type));
  if(the_piece->has_moved)
    printf("Has Moved\n");
  else
    printf("Has Not Moved\n");
  if(the_piece->occupation && !(called))
    debug_square(the_piece->occupation, 1);
  else
    printf("Unoccupied\n");
}

void free_piece(piece * the_piece) {
  if(the_piece)
    free(the_piece);
}
