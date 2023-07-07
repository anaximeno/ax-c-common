CC = gcc
FLAGS = -Wall -fPIC -g

SRCS = src/ax-log.c src/ax-result.c
OBJS = ax-log.o ax-result.o

TEST_SRCS = tests/tinytest/tinytest.c tests/test_memory.c
TEST_OBJS = tinytest.o test_memory.o

test: test_memory

test_memory: $(OBJS) $(TEST_OBJS)
	$(CC) $(FLAGS) $^ -o $@
	./$@ && rm $@

clean:
	rm *.o

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $^ -c

$(TEST_OBJS): $(TEST_SRCS)
	$(CC) $(FLAGS) $^ -c