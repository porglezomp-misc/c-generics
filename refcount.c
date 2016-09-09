#include <stdio.h>

#include "rc.h"

#define TYPE int
#include "rc_impl.h"
#undef TYPE

#define TYPE float
#include "rc_impl.h"
#undef TYPE

#define concat3_(A, B, C) A##_##B##_##C
#define assoc(K, V) concat3_(assoc, K, V)
#define make_assoc_ty(K, V) \
  typedef struct {          \
    K key;                  \
    V val;                  \
  } assoc(K, V)

make_assoc_ty(int, int);

typedef struct tree_node tree_node;
#define TYPE tree_node
#include "rc_impl.h"
#undef TYPE

struct tree_node {
  assoc(int, int) map;
  rc(tree_node) left, right;
};

int main() {
  tree_node tree_node_empty = { {0, 0}, rc_empty(tree_node)(), rc_empty(tree_node)() };
  rc(int) foo = rc_alloc(int)();
  rc_set(int)(&foo, 42);
  rc_free(int)(&foo);

  assoc(int, int) pair = { 0, 1 };
  printf("%d %d\n", pair.key, pair.val);
  tree_node root = {
    {0, 10},
    rc_make(tree_node)(tree_node_empty),
    rc_make(tree_node)(tree_node_empty),
  };

  return 0;
}
