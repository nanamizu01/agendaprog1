agenda: libAgenda.o mainAgenda.o
	gcc  libAgenda.o mainAgenda.o -o agenda

libAgenda.o: libAgenda.c
	gcc -Wall -Werror -Wextra -pedantic -c libAgenda.c

mainAgenda.o: mainAgenda.c 
	gcc -Wall -Werror -Wextra -pedantic -c mainAgenda.c

clean:
	rm -rf *.o agenda
