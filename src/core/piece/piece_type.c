#include "include/piece_type.h"

const char * piece_type_to_string(piece_type type) {
  switch(type) {
    case KING:   return "King";
    case QUEEN:  return "Queen";
    case ROOK:   return "Rook";
    case BISHOP: return "Bishop";
    case KNIGHT: return "Knight";
    case PAWN:   return "Pawn";
  }
  return NULL;
}
