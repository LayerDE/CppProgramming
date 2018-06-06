.PHONY: compile
.SUFFIXES:

CXX = g++ -Wall
HEADERS = $(wildcard *.h)

all: compile checkstyle

compile: ArraysAndPointersMain GameOfLifeMain

checkstyle:
	python ../cpplint.py --repository=. *.cpp

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test

GameOfLifeMain: GameOfLifeMain.o
	$(CXX) -o GameOfLifeMain GameOfLifeMain.o -lncurses

ArraysAndPointersMain: ArraysAndPointersMain.o
	$(CXX) -o ArraysAndPointersMain ArraysAndPointersMain.o -lncurses

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<
