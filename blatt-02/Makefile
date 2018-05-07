all: compile test checkstyle run

ApproximationEulersNumberMain: ApproximationEulersNumberMain.o ApproximationEulersNumber.o
	g++ -o ApproximationEulersNumberMain ApproximationEulersNumberMain.o ApproximationEulersNumber.o
	
ApproximationEulersNumberMain.o:
	g++ -c ApproximationEulersNumberMain.cpp ApproximationEulersNumberMain.cpp
	
ApproximationEulersNumber.o:
	g++ -c ApproximationEulersNumber.cpp

ApproximationEulersNumberTest: ApproximationEulersNumberMain.o ApproximationEulersNumber.o
	g++ -o ApproximationEulersNumberTest ApproximationEulersNumberTest.o ApproximationEulersNumber.o -lgtest -lpthread
	
ApproximationEulersNumberTest.o:
	g++ -c ApproximationEulersNumberTest.cpp

compile:
	ApproximationEulersNumberMain ApproximationEulersNumberTest
test:
	./ApproximationEulersNumberTest

checkstyle:
	python ../cpplint.py *.cpp
run:
	./ApproximationEulersNumberMain

clean:
	rm -f a.out
	rm -f *Main
	rm -f *Test
	rm -f *.o
