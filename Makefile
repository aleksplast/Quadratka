CC := g++
SRC = quadratka.cpp main.cpp
SRC_TEST = quadratka.cpp test.cpp
DIR = C:\Users\USER\Documents\quadratka

.PHONY: all clean

quadratka: $(SRC)
	$(CC) $^ -o $(DIR)\$@

test: $(SRC_TEST)
	$(CC) $^ -o $(DIR)\$@

clean:
	rm -rf *.exe
