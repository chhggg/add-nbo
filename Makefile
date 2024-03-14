#Makefile
all: add-nbo

add-nbo: main.o nbo.o
	g++ -o add-nbo main.o nbo.o

main.o: nbo.h main.cpp
	g++ -c -o main.o main.cpp

nbo.o: nbo.h nbo.cpp
	g++ -c -o nbo.o nbo.cpp


clean:
	rm -f add-nbo
	rm -f *.o
