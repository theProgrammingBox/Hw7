CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = Inventory.o 

all: Hw7

Hw7: Hw7.cpp Hw7.o
	$(CC) $(FLAGS) Hw7.cpp -o Hw7 $(OBJS)

Hw7.o: Hw7.cpp Inventory.o
	$(CC) $(FLAGS) -c Hw7.cpp -o Hw7.o

Inventory.o: Inventory.cpp Inventory.h
	$(CC) $(FLAGS) -c Inventory.cpp -o Inventory.o

clean:
	rm *.o *.tar *.scr Hw7

sudoClean:
	rm *.o *.scr Hw7

tar:
	tar cf Hw7.tar Hw7.scr Makefile Hw7.cpp Inventory.h Inventory.cpp