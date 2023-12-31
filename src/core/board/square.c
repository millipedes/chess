#include "include/square.h"
#include "core/piece/include/piece.h"

square * init_square(uint8_t rank, uint8_t file, color_attribute color) {
  square * the_square = calloc(1, sizeof(struct SQUARE_T));
  the_square->rank = rank;
  the_square->file = file;
  the_square->color = color;
  return the_square;
}

void debug_square(square * the_square, uint8_t called) {
  printf("[SQUARE]: %c%hd\n", file_to_algebraic(the_square->file),
      rank_to_algebraic(the_square->rank));
  if(the_square->occupation && !(called))
    debug_piece(the_square->occupation, 1);
  else if(!the_square->occupation)
    printf("Unoccupied\n");
}

uint8_t rank_to_algebraic(uint8_t rank) {
  return 8 - rank;
}

char file_to_algebraic(uint8_t file) {
  return (char)(file + 97);
}

uint8_t algebraic_rank(char rank) {
  return (uint8_t)(rank - 48);
}

uint8_t algebraic_file(char file) {
  return (uint8_t)(file - 97);
}

void free_square(square * the_square) {
  if(the_square)
    free(the_square);
}
