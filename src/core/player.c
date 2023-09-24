#include "include/player.h"

player * init_player(color_attribute color) {
  player * the_player = calloc(1, sizeof(struct PLAYER_T));
  the_player->color = color;
  the_player->pieces = calloc(QTY_PIECES, sizeof(struct PIECE_T *));
  for(int i = 0; i < QTY_PIECES; i++) {
    if(i == KING_INDEX)
      the_player->pieces[i] = init_piece(KING, color);
    else if(i == QUEEN_INDEX)
      the_player->pieces[i] = init_piece(QUEEN, color);
    else if(i == ROOK_ONE_INDEX || i == ROOK_TWO_INDEX)
      the_player->pieces[i] = init_piece(ROOK, color);
    else if(i == BISHOP_ONE_INDEX || i == BISHOP_TWO_INDEX)
      the_player->pieces[i] = init_piece(BISHOP, color);
    else if(i == KNIGHT_ONE_INDEX || i == KNIGHT_TWO_INDEX)
      the_player->pieces[i] = init_piece(KNIGHT, color);
    else
      the_player->pieces[i] = init_piece(PAWN, color);
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
