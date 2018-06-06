.SUFFIXES:

all: compile test checkstyle

compile: ApproximateEulersNumberMain

checkstyle:
	python ../cpplint.py --repository=. *.h *.cpp

test: ApproximateEulersNumberTest
	./ApproximateEulersNumberTest

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test

ApproximateEulersNumberMain: ApproximateEulersNumber.o ApproximateEulersNumberMain.o
	g++ -o ApproximateEulersNumberMain ApproximateEulersNumberMain.o ApproximateEulersNumber.o

ApproximateEulersNumberTest: ApproximateEulersNumber.o ApproximateEulersNumberTest.o
	g++ -o ApproximateEulersNumberTest ApproximateEulersNumberTest.o ApproximateEulersNumber.o -lgtest -lpthread

ApproximateEulersNumber.o: ApproximateEulersNumber.cpp ApproximateEulersNumber.h
	g++ -c ApproximateEulersNumber.cpp

ApproximateEulersNumberMain.o: ApproximateEulersNumberMain.cpp ApproximateEulersNumber.h
	g++ -c ApproximateEulersNumberMain.cpp

ApproximateEulersNumberTest.o: ApproximateEulersNumberTest.cpp ApproximateEulersNumber.h
	g++ -c ApproximateEulersNumberTest.cpp
