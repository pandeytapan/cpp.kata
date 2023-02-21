CC = g++
CFLAGS = -Wall -pg -g
CCOVERAGE = -fprofile-arcs -ftest-coverage

coverage: coverage.o
	$(CC) $(CFLAGS) $(CCOVERAGE) coverage.o

coverage.o: coverage.cpp
	$(CC) -c $(CFLAGS) $(CCOVERAGE) -c coverage.cpp

clean:
	rm -f *.o coverage *.gcda *.gcno *.gcov

