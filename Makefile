all:
	g++ quadratka.cpp main.cpp -o quadratka.o
debug:
	g++ -D_GLIBCXX_DEBUG quadratka.cpp main.cpp -o debug.o
test:
	g++ quadratka.cpp test.cpp -o test.o
