#ifndef COLOR_ATTRIBUTES_H
#define COLOR_ATTRIBUTES_H

#include <stdlib.h>

typedef enum {
  BLACK,
  WHITE,
} color_attribute;

const char * color_attribute_to_string(color_attribute attr);

#endif
