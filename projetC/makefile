vie: main.o  obj.o
	gcc -Wall -o $@ $^
main.o: main.c
	gcc -Wall -c $^
obj.o: obj.c obj.h
	gcc -Wall -c $^
clean:
	rm *.o | rm *.gch

