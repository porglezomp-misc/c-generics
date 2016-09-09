#ifndef INCLUDE_TREE_NODE_H
#define INCLUDE_TREE_NODE_H

#include "rc.h"

#define concat3_(A, B, C) A##_##B##_##C
#define assoc(K, V) concat3_(assoc, K, V)
#define make_assoc_ty(K, V)                     \
  typedef struct {                              \
    K key;                                      \
    V val;                                      \
  } assoc(K, V)

make_assoc_ty(int, int);

typedef struct tree_node tree_node;
#define TYPE tree_node
#include "just_rc.h"
#undef TYPE

typedef struct tree_node {
  assoc(int, int) map;
  rc(tree_node) left, right;
} tree_node;

#define TYPE tree_node
#define NO_DEFINE_TYPE
#include "rc_impl.h"
#undef NO_DEFINE_TYPE
#undef TYPE

#define NO_INCLUDE_IMPL

#endif
