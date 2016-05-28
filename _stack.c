#ifdef T

#include "generic.h"
#include "_stack.h"

#include <stdlib.h>

stack(T) *stack_alloc(T)(void) {
  return calloc(1, sizeof(stack(T)));
}

void stack_init(T)(stack(T) *s) {
  s->index = -1;
  s->block = NULL;
}

stack(T) *stack_make(T)(void) {
  stack(T) *s = stack_alloc(T)();
  stack_init(T)(s);
  return s;
}

void stack_free(T)(stack(T) *s) {
  free(s);
}

T stack_pop(T)(stack(T) *s) {
  if (s->index == -1) return 0;
  T value = s->block->elements[s->index--];
  if (s->index < 0 && s->block->prev_block) {
    s->block = s->block->prev_block;
    s->index = STACK_BLOCK_SIZE-1;
  }
  return value;
}

void stack_push(T)(stack(T) *s, T value) {
  if (s->block == NULL) {
    s->block = calloc(1, sizeof(*s->block));
  }
  if (s->index == STACK_BLOCK_SIZE-1) {
    s->block->next_block = calloc(1, sizeof(*s->block));
    s->block->next_block->prev_block = s->block;
    s->block = s->block->next_block;
    s->index = -1;
  }
  s->block->elements[++s->index] = value;
}

bool stack_is_empty(T)(stack(T) *s) {
  return s->index == -1;
}

#endif
