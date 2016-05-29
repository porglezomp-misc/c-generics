#ifdef T

#include "generic.h"
#include <stdbool.h>


#define STACK_BLOCK_SIZE 32
#define stack_block(T) GENERIC(T, stack_block)
typedef struct stack_block(T) {
  T elements[STACK_BLOCK_SIZE];
  struct stack_block(T) *prev_block;
  struct stack_block(T) *next_block;
} stack_block(T);


#define stack(T) GENERIC(T, stack)
typedef struct stack(T) {
  T index;
  stack_block(T) *block;
} stack(T);


#define stack_alloc(T) GENERIC(T, stack_alloc)
#define stack_init(T) GENERIC(T, stack_init)
#define stack_make(T) GENERIC(T, stack_make)
#define stack_free(T) GENERIC(T, stack_free)
stack(T) *stack_alloc(T)(void);
void stack_init(T)(stack(T) *);
stack(T) *stack_make(T)(void);
void stack_free(T)(stack(T) *);

#define stack_is_empty(T) GENERIC(T, stack_is_empty)
#define stack_pop(T) GENERIC(T, stack_pop)
#define stack_push(T) GENERIC(T, stack_push)
bool stack_is_empty(T)(stack(T) *);
T stack_pop(T)(stack(T) *);
void stack_push(T)(stack(T) *, T);

#endif
