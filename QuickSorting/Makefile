.PHONY: genRandom merging quicksort heapsort radixsort genSorted genReverse genSortedFirst genSortedLast 

CXXFLAGS = -std=c++11 -O2
CXX = g++

genRandom: genRandom.x
merging: merging.x
quicksort: quicksort.x
heapsort: heapsort.x
radixsort: radixsort.x
genSorted: genSorted.x
genReverse: genReverse.x
genSortedFirst: genSortedFirst.x
genSortedLast: genSortedLast.x

all: genRandom merging quicksort heapsort radixsort genSorted genReverse genSortedFirst genSortedLast

clean:
	rm *.x

cltext:
	rm input.txt
	rm output.txt
	rm input1.txt
	rm input2.txt
	rm input3.txt
	rm input4.txt

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test1:
	./genRandom.x 160000 100000  > input.txt
	./merging.x < input.txt > output.txt
	./quicksort.x < input.txt > output.txt
	./heapsort.x < input.txt > output.txt
	./radixsort.x < input.txt > output.txt

test2:
	./genSorted.x 80000 > input1.txt
	./genReverse.x 80000 > input2.txt
	./genSortedFirst.x 80000 > input3.txt
	./genSortedLast.x 80000 > input4.txt
	./radixsort.x < input1.txt > output.txt
	./radixsort.x < input2.txt > output.txt
	./radixsort.x < input3.txt > output.txt
	./radixsort.x < input4.txt > output.txt

qsort:
	gcc -O3 -march=native -o qsort.x qsort.c

stdsort:
	g++ -std=c++11 -O3 -march=native -o stdsort.x stdsort.cpp

