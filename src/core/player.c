#include "include/player.h"

player * init_player(color_attribute color) {
  player * the_player = calloc(1, sizeof(struct PLAYER_T));
  the_player->color = color;
  the_player->pieces = calloc(QTY_PIECES, sizeof(struct PIECE_T *));
  for(int i = 0; i < QTY_PIECES; i++) {
    if(i == 0)
      the_player->pieces[i] = init_piece(KING);
    else if(i == 1)
      the_player->pieces[i] = init_piece(QUEEN);
    else if(i == 2 || i == 3)
      the_player->pieces[i] = init_piece(ROOK);
    else if(i == 4 || i == 5)
      the_player->pieces[i] = init_piece(BISHOP);
    else if(i == 6 || i == 7)
      the_player->pieces[i] = init_piece(KNIGHT);
    else
      the_player->pieces[i] = init_piece(PAWN);
  }
  return the_player;
}

void debug_player(player * the_player) {
  printf("[PLAYER]: %s\n", color_attribute_to_string(the_player->color));
  for(int i = 0; i < QTY_PIECES; i++)
    debug_piece(the_player->pieces[i], 0);
}

void free_player(player * the_player) {
  if(the_player) {
    if(the_player->pieces) {
        for(int i = 0; i < QTY_PIECES; i++) {
          if(the_player->pieces[i])
            free_piece(the_player->pieces[i]);
        }
        free(the_player->pieces);
      }
      free(the_player);
    }
}
