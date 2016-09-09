#include <stdio.h>

#include "rc.h"

#define TYPE int
#include "rc_impl.h"
#undef TYPE

#define TYPE float
#include "rc_impl.h"
#undef TYPE

#include "tree_node.h"

rc(tree_node) tree_insert(rc(tree_node) tree, assoc(int, int) map) {
  tree_node node = rc_get(tree_node)(tree);
  rc(tree_node) empty = rc_empty(tree_node)();

  if (rc_is_empty(tree_node)(tree)) {
    return rc_make(tree_node)((tree_node) {map, empty, empty});
  }

  if (map.key < node.map.key) {
    rc(tree_node) new_left = tree_insert(node.left, map);
    rc_incref(tree_node)(node.right);
    return rc_make(tree_node)((tree_node) {node.map, new_left, node.right});
  } else if (map.key > node.map.key) {
    rc(tree_node) new_right = tree_insert(node.right, map);
    rc_incref(tree_node)(node.left);
    return rc_make(tree_node)((tree_node) {node.map, node.left, new_right});
  }

  rc_incref(tree_node)(node.left);
  rc_incref(tree_node)(node.right);
  return rc_make(tree_node)((tree_node) {map, node.left, node.right});
}

int main() {
  rc(int) foo = rc_alloc(int)();
  rc_set(int)(foo, 42);
  rc_free(int)(foo);

  assoc(int, int) pair = { 0, 1 };
  printf("%d %d\n", pair.key, pair.val);
  rc(tree_node) root = rc_empty(tree_node)();
  rc(tree_node) next = tree_insert(root, (assoc(int, int)) {5, 10});
  rc_free(tree_node)(root);
  next = tree_insert(next, (assoc(int, int)) {3, 42});
  next = tree_insert(next, (assoc(int, int)) {7, 9});

  return 0;
}
