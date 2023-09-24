#include "include/color_attribute.h"

const char * color_attribute_to_string(color_attribute attr) {
  switch(attr) {
    case BLACK: return "Black";
    case WHITE: return "White";
  }
  return NULL;
}
