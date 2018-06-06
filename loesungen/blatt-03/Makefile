CXX = g++ -Wall
HEADERS = $(wildcard *.h)
NAME = Ball

all: compile test checkstyle

compile: $(NAME)Main

test: $(NAME)Test
	./$(NAME)Test

checkstyle:
	python ../cpplint.py --repository=. *.h *.cpp

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test
	rm -f core

%Main: %Main.o $(NAME).o
	$(CXX) -o $@ $^ -lncurses

%Test: %Test.o $(NAME).o
	$(CXX) -o $@ $^ -lncurses -lgtest -lgtest_main -lpthread

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<
