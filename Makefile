all:
	g++ quadratka.cpp main.cpp -o quadratka
debug:
	g++ -D_GLIBCXX_DEBUG quadratka.cpp main.cpp -o debug
test:
	g++ quadratka.cpp test.cpp -o test
