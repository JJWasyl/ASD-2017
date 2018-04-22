.PHONY: deque stack genHeap queue heap containerTest genlist nawias genawias

CXXFLAGS = -std=c++11 -O2
CXX = g++

deque: deque.x
stack: stack.x
genHeap: genHeap.x
queue: queue.x
heap: heap.x
containerTest: containerTest.x
genlist: genlist.x
nawias: nawias.x
genawias: genawias.x

all: deque stack genHeap queue heap containerTest genlist nawias genawias

clean:
	rm *.x

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

