CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET = app1
SRCS = src/main.c src/metrics.c src/parser.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
