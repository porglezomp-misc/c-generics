#include <stdio.h>

struct env0 {
  int value;
};

struct closure0 {
  struct env0 *env;
  int (*fn)(struct env0*, int);
};

int add_env(struct env0 *env, int inc) {
  env->value += inc;
  return env->value;
}

int invoke_closure0(struct closure0 *closure, int arg) {
  return closure->fn(closure->env, arg);
}

int main() {
  struct env0 env = {0};
  struct closure0 cloj = {&env, &add_env};

  printf("%d %d %d\n",
         invoke_closure0(&cloj, 1),
         invoke_closure0(&cloj, 3),
         invoke_closure0(&cloj, 5));
  return 0;
}
