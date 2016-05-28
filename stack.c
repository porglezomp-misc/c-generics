#include "stack.h"

#include <stdlib.h>

stack *stack_alloc(void) {
  return calloc(1, sizeof(stack));
}

void stack_init(stack *s) {
  s->index = -1;
  s->block = NULL;
}

stack *stack_make(void) {
  stack *s = stack_alloc();
  stack_init(s);
  return s;
}

void stack_free(stack *s) {
  free(s);
}


int stack_pop(stack *s) {
  if (s->index == -1) return 0;
  int value = s->block->elements[s->index--];
  if (s->index < 0 && s->block->prev_block) {
    s->block = s->block->prev_block;
    s->index = STACK_BLOCK_SIZE-1;
  }
  return value;
}

void stack_push(stack *s, int value) {
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

bool stack_is_empty(stack *s) {
  return s->index == -1;
}
