p8: main.o bfs.o
	g++ -o p8 -std=c++11 main.o bfs.o
main.o: main.cpp bfs.h
	g++ -std=c++11 -c main.cpp
bfs.o: bfs.h bfs.cpp
	g++ -std=c++11 -c bfs.cpp
clean:
	rm -f p8 *.o *~
