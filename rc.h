#define concat(A, B) A##B

#define rc(T) concat(rc_, T)
#define rc_empty(T) concat(rc_empty_, T)
#define rc_alloc(T) concat(rc_alloc_, T)
#define rc_free(T) concat(rc_release_, T)
#define rc_incref(T) concat(rc_incref_, T)
#define rc_make(T) concat(rc_make_, T)
#define rc_set(T) concat(rc_set_, T)
#define rc_get(T) concat(rc_get_, T)
#define rc_is_empty(T) concat(rc_is_empty_, T)
