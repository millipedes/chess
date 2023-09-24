#include "include/square.h"
#include "core/piece/include/piece.h"

square * init_square(short file, short rank, color_attribute color) {
  square * the_square = calloc(1, sizeof(struct SQUARE_T));
  the_square->rank = rank;
  the_square->file = file;
  the_square->color = color;
  return the_square;
}

void debug_square(square * the_square, uint8_t called) {
  printf("[SQUARE]: %c%hd\n", file_to_algebraic(the_square->file),
      (the_square->rank + 1));
  if(the_square->occupation && !(called))
    debug_piece(the_square->occupation, 1);
  else
    printf("Unoccupied\n");
}

char file_to_algebraic(short file) {
  return (char)(file + 97);
}

void free_square(square * the_square) {
  if(the_square)
    free(the_square);
}
