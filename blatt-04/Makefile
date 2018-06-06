.PHONY: compile test checkstyle clean
.SUFFIXES:

CXX = g++ -Wall
HEADERS = $(wildcard *.h)
MAIN = $(basename $(wildcard *Main.cpp))
TEST = $(basename $(wildcard *Test.cpp))
OBJECTS = $(addsuffix .o, $(filter-out %Main %Test, $(basename $(wildcard *.cpp))))

.PRECIOUS: %.o

all: compile test checkstyle

compile: $(MAIN)

test: $(TEST)
	for T in $(TEST); do ./$$T; done

checkstyle:
	python3 ../cpplint.py --repository=. *.h *.cpp

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test
	rm -f core

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^ -lncurses

%Test: %Test.o $(OBJECTS)
	$(CXX) -o $@ $^ -lncurses -lgtest -lgtest_main -lpthread

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<
