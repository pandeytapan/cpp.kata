CC = g++
CFLAGS = -Wall -Werror -g -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs -ftest-coverage
SRC = coverage.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = coverage 

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE) *.gcov *.gcda *.gcno

test:
	./$(EXECUTABLE)
	gcov $(SRC)
	mkdir out || true
	lcov --directory . --capture --output-file out/coverage.info
	genhtml out/coverage.info --output-directory out/html

.PHONY: all clean test