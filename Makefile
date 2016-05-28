FLAGS = -Wall -Werror -Wextra -std=c99 -g

.PHONY: test clean
Test: test.c stack.o
	${CC} -o Test test.c stack.o ${FLAGS}

stack.o: stack.c _stack.c
	${CC} -c stack.c ${FLAGS}

test: Test
	./Test

clean:
	rm -f Test
	rm -f *.o
