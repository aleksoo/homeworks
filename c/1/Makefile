all: libstring.a 
	gcc -g -Wall -Wextra -Werror -std=c89 -pedantic-errors main.c lepszystring.o

libstring.a: lepszystring.o
	ar cr libstring.a lepszystring.o

lepszystring.o: 
	gcc -g -Wall -Wextra -Werror -std=c89 -pedantic-errors -c lepszystring.c

clean: 
	rm lepszystring.o libstring.a