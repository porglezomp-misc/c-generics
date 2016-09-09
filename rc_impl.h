#ifndef TYPE
#error "Please #define TYPE before including rc_impl.h"
// This is included to get better error messages while writing this file
#define TYPE int
#endif

#include "rc.h"
#include <stdbool.h>

#ifndef NO_DEFINE_TYPE
#include "just_rc.h"
#endif

rc(TYPE) rc_alloc(TYPE)();
rc(TYPE) rc_empty(TYPE)();
void rc_free(TYPE)(rc(TYPE) ref);
void rc_incref(TYPE)(rc(TYPE) ref);
rc(TYPE) rc_make(TYPE)(TYPE val);
void rc_set(TYPE)(rc(TYPE) ref, TYPE val);
TYPE rc_get(TYPE)(rc(TYPE) ref);
bool rc_is_empty(TYPE)(rc(TYPE) ref);
