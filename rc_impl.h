#ifndef TYPE
#error "Please #define TYPE before including rc_impl.h"
// This is included to get better error messages while writing this file
#define TYPE int
#endif

#include "rc.h"
#include <stdbool.h>

typedef struct rc(TYPE) rc(TYPE);

#define rc_cell(TYPE) concat(rc_cell_, TYPE)
struct rc(TYPE) {
  struct rc_cell(TYPE) *content;
};

rc(TYPE) rc_alloc(TYPE)();
rc(TYPE) rc_empty(TYPE)();
void rc_free(TYPE)(rc(TYPE) *ref);
void rc_incref(TYPE)(rc(TYPE) *ref);
rc(TYPE) rc_make(TYPE)(TYPE val);
void rc_set(TYPE)(rc(TYPE) *ref, TYPE val);
TYPE rc_get(TYPE)(rc(TYPE) *ref);
bool rc_is_empty(TYPE)(rc(TYPE) *ref);
