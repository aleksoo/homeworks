all: libstring.a 

libstring.a: lepszystring.o
	ar cr libstring.a lepszystring.o

lepszystring.o: 
	gcc -Wall -Wextra -Werror -std=c89 -pedantic-errors -c lepszystring.c

clean: 
	rm lepszystring.o libstring.a