#include "include/piece.h"
#include "core/board/include/square.h"

piece * init_piece(piece_type type, color_attribute color) {
  piece * the_piece = calloc(1, sizeof(struct PIECE_T));
  the_piece->type = type;
  the_piece->color = color;
  the_piece->occupation = NULL;
  the_piece->has_moved = 0;
  return the_piece;
}

uint8_t is_move_valid(piece * the_piece, square * the_square) {
  if(!the_piece->occupation) {
    return 0;
  } else {
    switch(the_piece->type) {
      case KING:   return is_king_move_valid(the_piece, the_square);
      case QUEEN:  return is_queen_move_valid(the_piece, the_square);
      case ROOK:   return is_rook_move_valid(the_piece, the_square);
      case BISHOP: return is_bishop_move_valid(the_piece, the_square);
      case KNIGHT: return is_knight_move_valid(the_piece, the_square);
      case PAWN:   return is_pawn_move_valid(the_piece, the_square);
    }
  }
  fprintf(stderr, "[IS_VALID_MOVE]: Something Went Wrong\nExiting\n");
  exit(1);
}

/**
 * This function assumes that the piece is occupying a square (i.e. it has not
 * been taken), will not function correctly otherwise (it will seg fault).
 * @param  the_piece - The piece which is being moved.
 * @param the_square - The square being checked if it can move to.
 * @return 1 - It is a Valid Move
 *         0 - It is Not a Valid Move
 */
uint8_t is_king_move_valid(piece * the_piece, square * the_square) {
  int rank_diff = the_piece->occupation->rank - the_square->rank;
  int file_diff = the_piece->occupation->file - the_square->file;
  if(rank_diff >= -1 && rank_diff <= 1 && rank_diff != 0
      && file_diff >= -1 && file_diff <= 1 && file_diff != 0)
    return 1;
  return 0;
}

uint8_t is_queen_move_valid(piece * the_piece, square * the_square) {
  if(is_rook_move_valid(the_piece, the_square)
      || is_bishop_move_valid(the_piece, the_square))
    return 1;
  return 0;
}

uint8_t is_rook_move_valid(piece * the_piece, square * the_square) {
  if(the_piece->occupation->rank == the_square->rank
      || the_piece->occupation->file == the_square->rank)
    return 1;
  return 0;
}

uint8_t is_bishop_move_valid(piece * the_piece, square * the_square) {
  int rank_diff = abs(the_piece->occupation->rank - the_square->rank);
  int file_diff = abs(the_piece->occupation->file - the_square->file);
  if(rank_diff == file_diff)
    return 1;
  return 0;
}

uint8_t is_knight_move_valid(piece * the_piece, square * the_square) {
  int rank_diff = abs(the_piece->occupation->rank - the_square->rank);
  int file_diff = abs(the_piece->occupation->file - the_square->file);
  if((rank_diff == 2 && file_diff == 1) || (rank_diff == 1 && file_diff == 2))
    return 1;
  return 0;
}

uint8_t is_pawn_move_valid(piece * the_piece, square * the_square) {
  if(the_piece->has_moved) {
    if(the_piece->color) {
      if(the_piece->occupation->rank - 1 == the_square->rank
          && the_piece->occupation->file == the_square->file) {
        return 1;
      }
    } else {
      if(the_piece->occupation->rank + 1 == the_square->rank
          && the_piece->occupation->file == the_square->file) {
        return 1;
      }
    }
    return 0;
  } else {
    if(the_piece->color) {
      if((the_piece->occupation->rank - 1 == the_square->rank
            || the_piece->occupation->rank - 2 == the_square->rank)
          && the_piece->occupation->file == the_square->file) {
        return 1;
      }
    } else {
      if((the_piece->occupation->rank + 1 == the_square->rank
            || the_piece->occupation->rank + 2 == the_square->rank)
          && the_piece->occupation->file == the_square->file) {
        return 1;
      }
    }
    return 0;
  }
}

void debug_piece(piece * the_piece, uint8_t called) {
  printf("[PIECE]: %s, %s, ", piece_type_to_string(the_piece->type),
      color_attribute_to_string(the_piece->color));
  if(the_piece->has_moved)
    printf("Has Moved\n");
  else
    printf("Has Not Moved\n");
  if(the_piece->occupation && !(called))
    debug_square(the_piece->occupation, 1);
  else if(!the_piece->occupation)
    printf("Unoccupied\n");
}

void free_piece(piece * the_piece) {
  if(the_piece)
    free(the_piece);
}
