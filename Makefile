CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = Hw7.o
FILES = Hw7.cpp Header.h

all: Hw7

Hw7: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o Hw7

Hw7.o: Hw7.cpp Header.h
	$(CC) $(FLAGS) -c Hw7.cpp

tar:
	tar -cf Hw7.tar Hw7.scr Makefile $(FILES)

clean:
	rm *.o *.tar *.scr Hw7

sudoClean:
	rm *.o *.scr Hw7