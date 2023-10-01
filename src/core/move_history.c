#include "include/move_history.h"

move * init_move(square * to, square * from, piece * the_piece,
    uint32_t move_no, color_attribute color) {
  move * the_move = calloc(1, sizeof(struct MOVE_T));
  the_move->to = to;
  the_move->from = from;
  the_move->the_piece = the_piece;
  the_move->move_no = move_no;
  the_move->color = color;
  return the_move;
}

void debug_move(move * the_move) {
  printf("[MOVE]\n");
  debug_square(the_move->to, 0);
  debug_square(the_move->from, 0);
  debug_piece(the_move->the_piece, 0);
  printf("Move No: %d, Color: %s\n", the_move->move_no,
      color_attribute_to_string(the_move->color));
}

void free_move(move * the_move) {
  if(the_move)
    free(the_move);
}

move_list * init_move_list(void) {
  move_list * the_move_list = calloc(1, sizeof(struct MOVE_LIST_T));
  the_move_list->next = NULL;
  the_move_list->this = NULL;
  the_move_list->prev = NULL;
  return the_move_list;
}

void debug_move_list(move_list * the_move_list) {
  if(the_move_list->this)
    debug_move(the_move_list->this);
  if(the_move_list->next)
    debug_move_list(the_move_list->next);
}

void free_move_list(move_list * the_move_list) {
  if(the_move_list) {
    if(the_move_list->this)
      free_move(the_move_list->this);
    if(the_move_list->next)
      free_move_list(the_move_list->next);
    free(the_move_list);
  }
}
