CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/matrix.c src/neuralnet.c
TEST = tests/test_nn.c

all: test

test:
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o test_nn -lm

clean:
	rm -f test_nn
