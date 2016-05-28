#include "stack.h"

#include <stdlib.h>

stack *stack_alloc(void) {
  return calloc(1, sizeof(stack));
}

void stack_init(stack *s) {
  s->index = 0;
  s->block = NULL;
}

stack *stack_make(void) {
  stack *s = stack_alloc();
  stack_init(s);
  return s;
}
