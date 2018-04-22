.PHONY: merging_repeat merging_unique gen2list gen1list sortAddRemove

CXXFLAGS = -std=c++11 -O2
CXX = g++

merging_repeat: merging_repeat.x
gen2list: gen2list.x
merging_unique: merging_unique.x
gen1list: gen1list.x
sortAddRemove: sortAddRemove.x

all: merging_repeat merging_unique gen2list gen1list sortAddRemove

clean:
	rm *.x

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

