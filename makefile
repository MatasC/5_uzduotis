make:
	g++ -c function.cpp
	g++ -std=c++14 main2.cpp function.o -o main
	./main
	rm *.o main