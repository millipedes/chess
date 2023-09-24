#include "include/board.h"

board * init_board(void) {
  board * the_board = calloc(1, sizeof(struct BOARD_T));
  for(int i = 0; i < FILES; i++) {
    for(int j = 0; j < RANKS; j++) {
      if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
        the_board->squares[i][j] = init_square(i, j, WHITE);
      else
        the_board->squares[i][j] = init_square(i, j, BLACK);
    }
  }
  return the_board;
}

void print_board(board * the_board) {
  for(int i = 0; i < FILES; i++) {
    for(int j = 0; j < RANKS; j++) {
      if(the_board->squares[i][j]->color == WHITE)
        printf(WHITE_CONSOLE_COLOR);
      else
        printf(BLACK_CONSOLE_COLOR);
      printf("# ");
      printf(CONSOLE_COLOR_OFF);
    }
    printf("\n");
  }
}

void free_board(board * the_board) {
  if(the_board) {
    for(int i = 0; i < FILES; i++) {
      for(int j = 0; j < RANKS; j++) {
        if(the_board->squares[i][j])
          free(the_board->squares[i][j]);
      }
    }
    free(the_board);
  }
}
