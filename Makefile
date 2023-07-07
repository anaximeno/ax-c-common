.PHONY : test_memory test_result

CC = gcc
FLAGS = -Wall -fPIC -g

SRCS = src/ax-log.c src/ax-result.c
OBJS = ax-log.o ax-result.o

TINYTEST_SRC = tests/tinytest/tinytest.c
TINYTEST_OBJ = tinytest.o

TEST_SRCS = tests/test_memory.c tests/test_result.c
TEST_OBJS = test_memory.o test_result.o

main: $(OBJS)

test: test_memory test_result

test_memory: $(TINYTEST_OBJ) $(OBJS) test_memory.o
	@echo -n "Running $@ -- "
	@$(CC) $(FLAGS) $^ -o $@
	-@./$@
	-@rm $@

test_result: $(TINYTEST_OBJ) $(OBJS) test_result.o
	@echo -n "Running $@ -- "
	@$(CC) $(FLAGS) $^ -o $@
	-@./$@
	-@rm $@

clean:
	rm *.o

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $^ -c

$(TEST_OBJS): $(TEST_SRCS)
	$(CC) $(FLAGS) $^ -c

$(TINYTEST_OBJ): $(TINYTEST_SRC)
	@$(CC) $(FLAGS) $^ -c
