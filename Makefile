FLAGS = -Wall -Werror -Wextra -std=c99 -g

.PHONY: test clean
Test: test.c stack.c
	${CC} -o Test test.c stack.c ${FLAGS}

test: Test
	./Test

clean:
	rm -f Test
