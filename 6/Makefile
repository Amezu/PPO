CXXFLAGS = -g -Wall --pedantic

all: main

main: Lab06.o
	g++ $(CXXFLAGS) *.o -o Lab06

Lab02.o: Lab06.cpp Lab06.h
	g++ $(CXXFLAGS) $< -c
	
clean:
	rm *.o Lab06
