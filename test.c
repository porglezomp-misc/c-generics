#include "minunit.h"
#include <stdbool.h>

#include "stack.h"

char *test_creation(void) {
  stack *s = stack_alloc();
  mu_assert(s, "An element should be allocated.");
  stack_init(s);
  mu_assert(s->index == -1, "The initial index should be -1");
  mu_assert(s->block == NULL, "There should initially be no block");

  stack s2;
  stack_init(&s2);
  mu_assert(s2.index == -1, "Intitial index should be -1");
  mu_assert(s2.block == NULL, "There should be initially no block");

  stack *s3 = stack_make();
  mu_assert(s3, "An element should be allocated");
  mu_assert(s3->index == -1, "Intitial index should be -1");
  mu_assert(s3->block == NULL, "There should be initially no block");

  stack_free(s);
  stack_free(s3);

  return NULL;
}

char *test_push_pop(void) {
  stack s;
  stack_init(&s);
  mu_assert(stack_pop(&s) == 0, "Popping an empty stack should produce 0");
  stack_push(&s, 42);
  mu_assert(stack_pop(&s) == 42, "We should pop the value we pushed");
  mu_assert(stack_pop(&s) == 0, "Popping an empty stack should produce 0");

  for (int i = 0; i < STACK_BLOCK_SIZE + 1; i++) {
    stack_push(&s, i);
  }
  mu_assert(stack_pop(&s) == STACK_BLOCK_SIZE, "Pop the last element");
  mu_assert(stack_pop(&s) == STACK_BLOCK_SIZE-1, "Pop the element before that");

  return NULL;
}

char *test_empty(void) {
  stack s;
  stack_init(&s);
  mu_assert(stack_is_empty(&s), "Stacks should be initially empty");
  stack_push(&s, 42);
  mu_assert(!stack_is_empty(&s), "Stack not empty with one item in it");
  stack_pop(&s);
  mu_assert(stack_is_empty(&s), "Stack should be empty with all items popped");

  for (int i = 0; i < STACK_BLOCK_SIZE*2; i++) {
    stack_push(&s, i);
    mu_assert(!stack_is_empty(&s), "Stack should not be empty with lots of items");
  }
  for (int i = 0; i < STACK_BLOCK_SIZE*2; i++) {
    mu_assert(!stack_is_empty(&s), "Stack should not be empty with lots of items");
    stack_pop(&s);
  }
  mu_assert(stack_is_empty(&s), "Stack should be empty again");

  return NULL;
}

char *test_suite(void) {
  mu_suite_start();

  mu_run_test(test_creation);
  mu_run_test(test_push_pop);
  mu_run_test(test_empty);

  return NULL;
}

RUN_TESTS(test_suite);
