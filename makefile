build:
	g++ main.cpp Board.cpp -o main.o

run: build
	./main.o