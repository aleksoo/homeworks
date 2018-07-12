a.out: main.o myBot.o
	g++ myBot.o main.o

myBot.o: myBot.cpp Makefile
	g++ -O0 -g -c myBot.cpp

main.o: main.cpp Makefile
	g++ -O0 -g -c main.cpp

clean:
	rm -f myBot.o main.o a.out
