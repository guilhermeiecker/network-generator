CC=g++
CFLAGS=-Wall -std=c++11

OBJ= generator.o Network.o Link.o Node.o

generator: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o generator

generator.o: generator.cc
	$(CC) $(CFLAGS) -c generator.cc

Network.o: Network.cc
	$(CC) $(CFLAGS) -c Network.cc

Link.o: Link.cc
	$(CC) $(CFLAGS) -c Link.cc

Node.o: Node.cc
	$(CC) $(CFLAGS) -c Node.cc

clean:
	rm *.o generator

clean-all:
	rm *.o generator *.txt
