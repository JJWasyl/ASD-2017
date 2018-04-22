.PHONY: slownik

CXXFLAGS = -std=c++11 -O2
CXX = g++

slownik: slownik.x


all: slownik

clean: 
	rm *.x

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

