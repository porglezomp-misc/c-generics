#include "minunit.h"
#include <stdbool.h>

char *passing_test(void) {
  mu_assert(true, "This test should pass");
  return NULL;
}

char *failing_test(void) {
  mu_assert(false, "This test probably just failed");
  return NULL;
}

char *test_suite(void) {
  mu_suite_start();

  mu_run_test(passing_test);
  mu_run_test(failing_test);

  return NULL;
}

RUN_TESTS(test_suite);
