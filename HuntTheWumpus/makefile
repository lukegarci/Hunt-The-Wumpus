CC=g++ -std=c++11 -g
exe=asm4

all: $(exe)

$(exe): bats.h event.h game.h gold.h room.h stalactites.h wumpus.h bats.o event.o game.o gold.o room.o \
 			stalactites.o main.o wumpus.o
	$(CC) bats.o event.o game.o gold.o room.o stalactites.o main.o wumpus.o -o $(exe)

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

stalactites.o: stalactites.h stalactites.cpp
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

main.o: main.cpp game.h
	$(CC) -c main.cpp


clean:
	rm -f *.o $(exe)