.SUFFIXES:

all: compile test checkstyle

compile:
	g++ -c ApproximationOfPi.cpp
	g++ -c ApproximationOfPiMain.cpp
	g++ -c ApproximationOfPiTest.cpp
	g++ -o ApproximationOfPiMain ApproximationOfPiMain.o ApproximationOfPi.o
	g++ -o ApproximationOfPiTest ApproximationOfPiTest.o ApproximationOfPi.o -lgtest -lpthread

test:
	./ApproximationOfPiTest

checkstyle:
	python ../cpplint.py --repository=. *.cpp *.h

clean:
	rm -f a.out
	rm -f ApproximationOfPiMain
	rm -f ApproximationOfPiTest
	rm -f *.o
