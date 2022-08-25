cc = g++

.PHONY: all clean

square:
	$(cc) quadratka.cpp main.cpp -o quadratka
debug:
	$(cc) -D_GLIBCXX_DEBUG quadratka.cpp main.cpp -o debug
test:
	$(cc) quadratka.cpp test.cpp -o test
clean:
	rm -rf *.exe

#-MD -MMD, регулярные выражения в makefile
