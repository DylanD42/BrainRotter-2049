CC = g++
CFLAGS = -g -Wall -Wextra

default: brainrot

brainrot:	main.o
	$(CC) $(CLFAGS) -o brainrot main.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp
clean:
	$(RM) brainrot *.o *~
