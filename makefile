CFLAGS = -Wall -ansi -pedantic -Werror -g
OBJS = main.o color.o newSleep.o linkedList.o createArray.o swapNumbers.o checkInteger.o printNumbers.o selectionSort.o
CC = gcc
EXEC = myProgram

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) 

main.o: main.c createArray.h checkInteger.h selectionSort.h
	$(CC) $(CFLAGS) -c main.c

color.o: color.c color.h 
	$(CC) $(CFLAGS) -c color.c

newSleep.o: newSleep.c newSleep.h
	$(CC) $(CFLAGS) -c newSleep.c

linkedList.o: linkedList.c linkedList.h color.h
	$(CC) $(CFLAGS) -c linkedList.c
	
createArray.o: createArray.c createArray.h checkInteger.h
	$(CC) $(CFLAGS) -c createArray.c  
	
swapNumbers.o: swapNumbers.c swapNumbers.h color.h newSleep.h
	$(CC) $(CFLAGS) -c swapNumbers.c

checkInteger.o: checkInteger.c checkInteger.h
	$(CC) $(CFLAGS) -c checkInteger.c

printNumbers.o: printNumbers.c printNumbers.h color.h newSleep.h
	$(CC) $(CFLAGS) -c printNumbers.c

selectionSort.o: selectionSort.c selectionSort.h linkedList.h swapNumbers.h printNumbers.h
	$(CC) $(CFLAGS) -c selectionSort.c
	
clean:
	rm -f $(OBJS) $(EXEC)                                        
