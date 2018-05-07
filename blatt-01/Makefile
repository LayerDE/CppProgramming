all: compile test checkstyle run

compile:
	g++ -o ApproximationEulersNumberMain *Main.cpp
	g++ -o ApproximationEulersNumberTest *Test.cpp -lgtest -lpthread

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
