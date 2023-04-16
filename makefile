CC = gcc

CFLAGS = -g  -Wall -Werror -Wextra -pedantic
LDFLAGS = -lm

main: libAgenda.o mainAgenda.o
	$(CC) mainAgenda.o libAgenda.o -o tp2  $(LDFLAGS)

mainAgenda.o : mainAgenda.c	
	$(CC) $(CFLAGS) -c mainAgenda.c

libAgenda.o : libAgenda.c
	$(CC) $(CFLAGS) -c libAgenda.c

clean :
	rm *.o tp2

