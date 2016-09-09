CFLAGS=-Wall -Wextra -Werror -pedantic -std=c11

Refcount: refcount.o rc_int.o rc_float.o rc_tree_node.o
	gcc -o $@ $^ $(CFLAGS)

rc_tree_node.o: rc.h rc_impl.c rc_impl.h
	gcc -c rc_impl.c -D TYPE=tree_node -D TYPE_HEADER='"tree_node.h"' -o $@ $(CFLAGS)

rc_%.o: rc.h rc_impl.c rc_impl.h
	gcc -c rc_impl.c -D TYPE=$* -o $@ $(CFLAGS)

clean:
	rm -f *.o
	rm -f Refcount
