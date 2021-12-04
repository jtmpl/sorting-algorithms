CXX ?= c++
CXXFLAGS ?= -std=c++11 -O2 -Wall -Wextra -Wpedantic

.PHONY: all run test clean

all: prac1

prac1: prac1.cpp
	$(CXX) $(CXXFLAGS) prac1.cpp -o prac1

run: prac1
	./prac1

test: prac1
	./prac1 --test

clean:
	rm -f prac1
	rm -rf prac1.dSYM
