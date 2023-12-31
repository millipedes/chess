#include "include/game.h"

game * init_game(void) {
  game * the_game = calloc(1, sizeof(struct GAME_T));
  the_game->the_board = init_board();
  the_game->players[0] = init_player(WHITE);
  the_game->players[1] = init_player(BLACK);
  setup_board(the_game->players[0], the_game->the_board);
  setup_board(the_game->players[1], the_game->the_board);
  the_game->current_move = 0;
  the_game->the_move_list = init_move_list();
  return the_game;
}

void setup_board(player * the_player, board * the_board) {
  // Back Row for White is 7 and for Black is 0
  int file_offset = (the_player->color ? 7 : 0);
  // King
  assert_occupation(the_player->pieces[KING_INDEX],
      the_board->squares[file_offset][4]);
  // Queen
  assert_occupation(the_player->pieces[QUEEN_INDEX],
      the_board->squares[file_offset][3]);
  // Rook
  assert_occupation(the_player->pieces[ROOK_ONE_INDEX],
      the_board->squares[file_offset][0]);
  assert_occupation(the_player->pieces[ROOK_TWO_INDEX],
      the_board->squares[file_offset][7]);
  // Bishop
  assert_occupation(the_player->pieces[BISHOP_ONE_INDEX],
      the_board->squares[file_offset][5]);
  assert_occupation(the_player->pieces[BISHOP_TWO_INDEX],
      the_board->squares[file_offset][2]);
  // Knight
  assert_occupation(the_player->pieces[KNIGHT_ONE_INDEX],
      the_board->squares[file_offset][1]);
  assert_occupation(the_player->pieces[KNIGHT_TWO_INDEX],
      the_board->squares[file_offset][6]);
  // If White, Move Offset Up One, Otherwise Move Down One
  file_offset += (the_player->color ? -1 : 1);
  // Pawn
  for(int i = 0; i < 8; i++) {
    assert_occupation(the_player->pieces[i + 8],
        the_board->squares[file_offset][i]);
  }
}

void move_piece(game * the_game, piece * the_piece, square * the_square) {
  if(is_move_valid(the_piece, the_square)) {
    the_game->current_move++;
    the_game->the_move_list = add_move(the_game->the_move_list,
        init_move(the_piece->occupation, the_square, the_piece,
          the_game->current_move, the_piece->color));
    revert_occupation(the_piece, the_piece->occupation);
    assert_occupation(the_piece, the_square);
    if(!the_piece->has_moved)
      the_piece->has_moved = 1;
  } else {
    fprintf(stderr, "[MOVE]: Invalid Move, Please Try Again\n");
  }
}

void revert_occupation(piece * the_piece, square * the_square) {
  the_piece->occupation = NULL;
  the_square->occupation = NULL;
}

void assert_occupation(piece * the_piece, square * the_square) {
  the_piece->occupation = the_square;
  the_square->occupation = the_piece;
}

void debug_game(game * the_game) {
  printf("[GAME]: move no. %u\n", the_game->current_move);
  print_board(the_game->the_board);
  debug_player(the_game->players[0]);
  debug_player(the_game->players[1]);
  debug_move_list(the_game->the_move_list);
}

void free_game(game * the_game) {
  if(the_game) {
    if(the_game->the_board)
      free_board(the_game->the_board);
    if(the_game->players[0])
      free_player(the_game->players[0]);
    if(the_game->players[1])
      free_player(the_game->players[1]);
    if(the_game->the_move_list)
      free_move_list(the_game->the_move_list);
    free(the_game);
  }
}
