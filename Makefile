CC = gcc
LDFLAGS = -lncurses

SRCS = main.c game.c
TARGET = perryTyper

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
