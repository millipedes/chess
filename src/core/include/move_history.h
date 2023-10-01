#ifndef MOVE_HISTORY_H
#define MOVE_HISTORY_H

#include "core/board/include/square.h"
#include "core/include/color_attribute.h"
#include "core/piece/include/piece.h"

typedef struct MOVE_T {
  square * to;
  square * from;
  piece * the_piece;
  uint32_t move_no;
  color_attribute color;
} move;

move * init_move(square * to, square * from, piece * the_piece,
    uint32_t move_no, color_attribute color);
void debug_move(move * the_move);
void free_move(move * the_move);

typedef struct MOVE_LIST_T {
  struct MOVE_LIST_T * next;
  move * this;
  struct MOVE_LIST_T * prev;
} move_list;

move_list * init_move_list(void);
move_list * add_move(move_list * head, move * new_move);
void debug_move_list(move_list * the_move_list);
void free_move_list(move_list * the_move_list);

#endif
