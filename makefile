output: main.o dealer.o
	g++ main.o dealer.o -o cards

main.o: main.cpp
	g++ -c main.cpp

dealer.o: dealer.h dealer.cpp
	g++ -c dealer.cpp

test: test.o dealer.o
	g++ test.o dealer.o -o test

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm *.o cards test
