CC = gcc
all: bin/main

bin/main: obj/main.o 
	$(CC) -o $@ $^ -lm -lpthread -fopenmp

obj/main.o: src/main.c
	$(CC) $< -c -o $@ -lm -lpthread -fopenmp

run: 
	@./bin/main

clean:
	rm -rf ./bin/* ./obj/*.o