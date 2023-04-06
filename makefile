all: agenda
agenda: libAgenda.o main.o
	gcc -o libAgenda.o main.o

libAgenda.o: libAgenda.c
	gcc -o libAgenda.o libAgenda.c -Wall -Werror -Wextra -pedantic

main.o: main.c libAgenda.h
	gcc -o main.o main.c -Wall -Werror -Wextra -pedantic

clean:
	rm -rf *.o
mrproper: clean
	rm -rf agenda
