# Compiler and flags
CC = gcc
CFLAGS = -fsanitize=address -Wall -Wextra -g -I../munit

# Source files
SRCS = main.c snekobject.c
BINS = ../bin/

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = refcount_app

# Path to munit library
MUNIT_PATH = ../munit

# Munit object file
MUNIT_OBJ = $(MUNIT_PATH)/munit.o

# Default rule
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJS) $(MUNIT_OBJ)
	$(CC) $(CFLAGS) -o $(BINS)$(TARGET) $(OBJS) $(MUNIT_OBJ)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile munit.c to munit.o
$(MUNIT_OBJ): $(MUNIT_PATH)/munit.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET) $(MUNIT_OBJ)
