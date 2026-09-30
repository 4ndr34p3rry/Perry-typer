CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lncurses

SRCS = main.c game.c
TARGET = perryTyper

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
