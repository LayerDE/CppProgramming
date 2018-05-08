all: compile test checkstyle

compile:
	g++ -o ApproximationOfPiMain ApproximationOfPiMain.cpp
	g++ -o ApproximationOfPiTest ApproximationOfPiTest.cpp -lgtest -lpthread

test:
	./ApproximationOfPiTest

checkstyle:
	python cpplint.py *.cpp

clean:
	rm -f a.out
	rm -f ApproximationOfPiMain
	rm -f ApproximationOfPiTest
