#ifndef TYPE
#error "Please #define TYPE before including rc_impl.c"
// This is included to get better error messages while writing this file
#define TYPE int
#endif

#include "rc.h"
#include "rc_impl.h"

#include <stdint.h>
#include <stdlib.h>

struct rc_cell(TYPE) {
  TYPE value;
  intptr_t count;
};

rc(TYPE) rc_empty(TYPE)() {
  return (rc(TYPE)) { 0 };
}

rc(TYPE) rc_alloc(TYPE)() {
  struct rc_cell(TYPE) *cell = calloc(1, sizeof (struct rc_cell(TYPE)));
  cell->count = 1;
  return (rc(TYPE)) { cell };
}

void rc_free(TYPE)(rc(TYPE) *ref) {
  ref->content->count--;
  if (ref->content->count <= 0) {
    free(ref->content);
  }
}

void rc_incref(TYPE)(rc(TYPE) *ref) {
  if (rc_is_empty(TYPE)(ref)) { return; }
  ref->content->count++;
}

rc(TYPE) rc_make(TYPE)(TYPE val) {
  rc(TYPE) ref = rc_alloc(TYPE)();
  rc_set(TYPE)(&ref, val);
  return ref;
}

void rc_set(TYPE)(rc(TYPE) *ref, TYPE val) {
  ref->content->value = val;
}

TYPE rc_get(TYPE)(rc(TYPE) *ref) {
  return ref->content->value;
}

bool rc_is_empty(TYPE)(rc(TYPE) *ref) {
  return ref->content == NULL;
}
