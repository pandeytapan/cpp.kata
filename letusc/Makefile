# Simple Makefile for the C project

# Define the various variables
# ############################

# Variable defining the compiler to use
CC = gcc
# Give all and extra warnings while compiling
CFLAGS = -Wall -Wextra
# The TARGET name is overridable from the command line
TARGET ?= a.out
# All the C source files
SRCS = first.c
# Convert .c files into the .obj files
OBJS = $(SRCS:.c=.o)

# Targets
#########

# Default target all will try to build the $(TARGET)
all: $(TARGET)

# Compilation step is implicit rule that is used by the make system implicitly
# Compiles the .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking Step builds target whose prerequsitive is OBJS
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Running the program
test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean test
