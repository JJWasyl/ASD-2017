.PHONY: testTree

CXXFLAGS = -std=c++11 -O2
CXX = g++

testTree: testTree.x


all: testTree

clean: 
	rm *.x

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

