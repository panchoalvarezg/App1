CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = main.o parser.o metrics.o utils.o

app1: $(OBJS)
	$(CC) $(CFLAGS) -o app1 $(OBJS)

clean:
	rm -f *.o app1
