# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -g

# Find all .c files in the current directory
SRCS = $(wildcard *.c)

# Generate object files for each source file
OBJS = $(SRCS:.c=.o)

# Output executable name
TARGET = program.exe

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file into .o (object file)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	del /Q *.o $(TARGET)
