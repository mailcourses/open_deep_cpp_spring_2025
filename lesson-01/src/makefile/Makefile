
CC=g++
FLAGS=-std=c++20 -Wall -Wextra -pedantic
EXEC=main

main: vector.o main.o
	$(CC) $(FLAGS) vector.o main.o -o $(EXEC)

vector.o: vector.cpp vector.hpp
	$(CC) $(FLAGS) -c vector.cpp

main.o: vector.hpp main.cpp
	$(CC) $(FLAGS) -c main.cpp

very_bad:
	g++ -std=c++20 -Wall -Wextra -pedantic main.cpp vector.cpp -o main

clean:
	rm -f *.o $(EXEC)
