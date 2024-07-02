CC = gcc
CFLAGS = -Wall -Wextra -I.
LDFLAGS = -lSDL2

SRC = test.c window.c
OBJ = $(SRC:.c=.o)
TARGET = test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
