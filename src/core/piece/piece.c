#include "include/piece.h"
#include "core/board/include/square.h"

void debug_piece(piece the_piece, uint8_t called) {
  printf("[PIECE]: (%s, %s)\n", color_attribute_to_string(the_piece.color),
      piece_type_to_string(the_piece.type));
  if(the_piece.occupation && !(called))
    debug_square(*the_piece.occupation, 1);
}
