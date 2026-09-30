CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lncurses

# Sostituisci main.c e utils.c con i nomi reali dei tuoi file .c
SRCS = main.c utils.c
TARGET = mio_programma

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
