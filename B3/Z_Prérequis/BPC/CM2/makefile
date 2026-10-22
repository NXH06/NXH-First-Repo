CC = gcc
CFLAGS = -ansi -Wall -pedantic -c
LDFLAGS =
EXEC = test.out

all: test.out

test.out: test.o fact.o
	$(CC) -o $@ $^ $(LDFLAGS)
test.o: test.c fact.h
	$(CC) -o $@ -c $< $(CFLAGS)
fact.o: fact.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean
clean:
	-rm *.o
fclean: clean
	-rm $(EXEC)