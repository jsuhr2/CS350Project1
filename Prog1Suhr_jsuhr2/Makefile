all: prog1sorter prog1generator

parser.o: parser.c
	gcc -c parser.c

prog1sorter.o: prog1sorter.c
	gcc -c prog1sorter.c

prog1sorter: prog1sorter.o parser.o
	gcc prog1sorter.o parser.o -o prog1sorter

prog1generator.o: prog1generator.c
	gcc -c prog1generator.c

prog1generator: prog1generator.o parser.o
	gcc prog1generator.o parser.o -o prog1generator

clean:
	rm prog1sorter.o
	rm prog1sorter
	rm prog1generator.o
	rm prog1generator
	rm parser.o
	rm -fv *~ \#*\# *.swp
	rm -fv *.txt
