#include "include/square.h"
#include "core/piece/include/piece.h"

void debug_square(square the_square, uint8_t called) {
  printf("[SQUARE]: %c%hd\n", file_to_algebraic(the_square.file),
      (the_square.rank + 1));
  if(the_square.occupation && !(called))
    debug_piece(*the_square.occupation, 1);
}

char file_to_algebraic(short file) {
  return (char)(file + 97);
}
