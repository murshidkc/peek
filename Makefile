CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iheaders
LDFLAGS = -lm
SRC = src/main.c
TARGET = peek

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

