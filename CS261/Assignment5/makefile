all: prog

prog: dynamicArray.o main.o toDoList.o
	gcc -g -Wall -std=c99 -o prog dynamicArray.o toDoList.o main.o
	
main.o: main.c dynamicArray.h toDoList.h
	gcc -g -Wall -std=c99 -c main.c
	
dynamicArray.o: dynamicArray.c dynamicArray.h
	gcc -g -Wall -std=c99 -c dynamicArray.c
	
toDoList.o: toDoList.c toDoList.h
	gcc -g -Wall -std=c99 -c toDoList.c

clean:	
	rm dynamicArray.o
	rm toDoList.o
	rm main.o
	rm prog