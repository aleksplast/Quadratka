cc = g++

.PHONY: all debug test

square:
	$(cc) quadratka.cpp main.cpp -o quadratka.o
debug:
	$(cc) -D_GLIBCXX_DEBUG quadratka.cpp main.cpp -o debug.o
test:
	$(cc) quadratka.cpp test.cpp -o test.o
clean:
	rm *.o temp

#-MD -MMD, регулярные выражения в makefile

