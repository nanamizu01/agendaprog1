
agenda: libAgenda.o main.o
	gcc  libAgenda.o main.o -o agenda

libAgenda.o: libAgenda.c
	gcc -Wall -Werror -Wextra -pedantic -c libAgenda.c

main.o: main.c 
	gcc -Wall -Werror -Wextra -pedantic -c main.c

clean:
	rm -rf *.o agenda
