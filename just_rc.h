#ifndef TYPE
#error "Please #define TYPE before including rc_impl.h"
// This is included to get better error messages while writing this file
#define TYPE int
#endif

typedef struct rc(TYPE) rc(TYPE);

#define rc_cell(TYPE) concat(rc_cell_, TYPE)
struct rc(TYPE) {
  struct rc_cell(TYPE) *content;
};
