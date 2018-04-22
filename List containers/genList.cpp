/* 
 * 2017 (C) Andrzej Görlich
 * Compilation: g++ -std=c++11 -O2 -o genList.x genList.cpp
 */
 

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int maxval = 10000;

int main(int argc, char *argv[]) {
int n;															// Output size

	if(argc != 2) {
		cerr << "Please set ouput size\n";
		return 1;
	}

	srand(time(nullptr));
	
	n	= atoi(argv[1]);

	if(n <= 0) {
		cerr << "Incorrect ouput size\n";
		return 1;
	}

	cout << n << endl;
	for (int i = 0; i < n; ++i)
	{
		double x	= (double) rand() / RAND_MAX;
		if(x < 0.4)
			cout << "A " << rand() % maxval << endl;			// 40% chance for add
		else if(x < 0.6)
			cout << "F " << rand() % maxval << endl;			// 10% chance for find
		else if(x < 0.9)
			cout << "D\n";										// 30% chance for delete
		else
			cout << "S\n";										// 10% chance for size
	}

	return 0;
}
