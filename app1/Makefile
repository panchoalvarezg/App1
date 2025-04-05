CC = gcc
CFLAGS = -Iinclude

all: app1

app1: src/main.o src/parser.o src/metrics.o
    $(CC) -o app1 src/main.o src/parser.o src/metrics.o

src/main.o: src/main.c
    $(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/parser.o: src/parser.c
    $(CC) $(CFLAGS) -c src/parser.c -o src/parser.o

src/metrics.o: src/metrics.c
    $(CC) $(CFLAGS) -c src/metrics.c -o src/metrics.o

clean:
    rm -f app1 src/*.o
