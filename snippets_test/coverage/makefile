CC = g++
cover: coverage.cpp
	$(CC) -fprofile-arcs -ftest-coverage -o coverage coverage.cpp
	./coverage
	gcov coverage.cpp
