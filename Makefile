CC := g++
SRC := quadratka.cpp main.cpp
SRC_TEST := quadratka.cpp test.cpp
SRC_PARSER := quadratka.cpp main.cpp parser.cpp
DIR := C:\Users\USER\Documents\quadratka

.PHONY: all clean

quadratka: $(SRC)
	$(CC) $^ -o $(DIR)\$@

test: $(SRC_TEST)
	$(CC) $^ -o $(DIR)\$@

run: $(DIR)\quadratka.exe
	$(DIR)\quadratka.exe

parser: $(SRC_PARSER)
	$(CC) $^ -o $(DIR)\$@

clean:
	rm -rf *.exe
