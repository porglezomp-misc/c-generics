#include "minunit.h"
#include <stdbool.h>

#define STACK_BLOCK_SIZE 8
#include "stack.h"

char *test_creation(void) {
  stack *s = stack_alloc();
  mu_assert(s, "An element should be allocated.");
  stack_init(s);
  mu_assert(s->index == 0, "The initial index should be zero");
  mu_assert(s->block == NULL, "There should initially be no block");

  stack s2;
  stack_init(&s2);
  mu_assert(s2.index == 0, "Intitial index should be zero");
  mu_assert(s2.block == NULL, "There should be initially no block");

  stack *s3 = stack_make();
  mu_assert(s3->index == 0, "Intitial index should be zero");
  mu_assert(s3->block == NULL, "There should be initially no block");

  return NULL;
}

char *test_suite(void) {
  mu_suite_start();

  mu_run_test(test_creation);

  return NULL;
}

RUN_TESTS(test_suite);
