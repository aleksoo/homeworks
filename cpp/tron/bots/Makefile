a.out: clean main.o killer3.o graph.o
	g++ killer3.o graph.o main.o -o aleksander

graph.o: graph.cpp
	g++ -O0 -g -c graph.cpp

killer3.o: killer3.cpp Makefile
	g++ -O0 -g -c killer3.cpp

main.o: main.cpp
	g++ -O0 -g -c main.cpp

clean:
	rm -f killer3.o main.o a.out
