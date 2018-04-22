.PHONY: fib test

CXXFLAGS = -std=c++11 -O2
CXX = g++

fib: fib.x
test: test.x


all: fib test

clean: 
	rm *.x

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

