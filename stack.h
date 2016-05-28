#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>

#define STACK_BLOCK_SIZE 32
typedef struct stack_block {
  int elements[STACK_BLOCK_SIZE];
  struct stack_block *prev_block;
  struct stack_block *next_block;
} stack_block;

typedef struct stack {
  int index;
  stack_block *block;
} stack;

stack *stack_alloc(void);
void stack_init(stack *);
stack *stack_make(void);
void stack_free(stack *);

bool stack_is_empty(stack *);
int stack_pop(stack *);
void stack_push(stack *, int);
bool stack_push_prealloc(stack *, int, stack_block *);

#endif
