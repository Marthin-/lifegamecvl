vie: affichage.o constantes.o main.o regles_de_vie.o remplir.o
	gcc -Wall -o $@ $^ -lm ./usr/lib/libSDL-1.2.so.0.11.4
%.o: %.c
	gcc -Wall -c $^
clean:
	rm *.o && rm vie

