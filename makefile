build:
	g++ main.cpp Board.cpp -o main.o

run: build
	./main.o

debug_build:
	g++ -g main.cpp Board.cpp -o main.o

dr:
	lddb main.o