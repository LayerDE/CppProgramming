.SUFFIXES

all: compile test checkstyle run

ApproximationEulersNumberMain: ApproximationEulersNumberMain.o ApproximationEulersNumber.o
	g++ -o ApproximationEulersNumberMain ApproximationEulersNumberMain.o ApproximationEulersNumber.o
	
ApproximationEulersNumberMain.o: ApproximationEulersNumberMain. ApproximationEulersNumber.h
	g++ -std=c++11 -c ApproximationEulersNumberMain.cpp
	
ApproximationEulersNumber.o: ApproximationEulersNumber.cpp ApproximationEulersNumber.h
	g++ -std=c++11 -c ApproximationEulersNumber.cpp

ApproximationEulersNumberTest: ApproximationEulersNumberMain.o ApproximationEulersNumber.o
	g++ -o ApproximationEulersNumberTest ApproximationEulersNumberTest.o ApproximationEulersNumber.o -lgtest -lpthread
	
ApproximationEulersNumberTest.o: ApproximationEulersNumberTest.cpp ApproximationEulersNumber.h
	g++ -std=c++11 -c ApproximationEulersNumberTest.cpp

compile: ApproximationEulersNumberMain ApproximationEulersNumberTest

test:
	./ApproximationEulersNumberTest

checkstyle:
	touch .svn
	python ../cpplint.py *.cpp
	rm -f .svn
run:
	./ApproximationEulersNumberMain

clean:
	rm -f a.out
	rm -f *Main
	rm -f *Test
	rm -f *.o
