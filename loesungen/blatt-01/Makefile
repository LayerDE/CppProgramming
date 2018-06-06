all: compile test checkstyle

compile:
	g++ -o ApproximateEulersNumberMain ApproximateEulersNumberMain.cpp
	g++ -o ApproximateEulersNumberTest ApproximateEulersNumberTest.cpp -lgtest -lpthread

checkstyle:
	python ../cpplint.py *.cpp

test:
	./ApproximateEulersNumberTest

clean:
	rm -f *Main
	rm -f *Test
