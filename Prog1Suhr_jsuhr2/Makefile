all: prog1sorter prog1generator

prog1sorter.o: prog1sorter.c
	gcc -c prog1sorter.c

prog1sorter: prog1sorter.o
	gcc prog1sorter.o -o prog1sorter

prog1generator.o: prog1generator.c
	gcc -c prog1generator.c

prog1generator: prog1generator.o
	gcc prog1generator.o -o prog1generator

clean:
	rm prog1sorter.o
	rm prog1sorter
	rm prog1generator.o
	rm prog1generator
	rm -fv *~ \#*\# *.swp
