/* 
 * 2017 (C) Andrzej Görlich
 * Compilation: g++ -std=c++11 -O2 -o genHeap.x genHeap.cpp
 */
 
#include <iostream>
#include <string>
#include <random>

constexpr auto maximal = 1000000;

auto main(int argc, char *argv[]) -> int {

	if(argc != 2) {
		std::cerr << "Please set ouput size\n";
		return 1;
	}

	auto number	 = std::stoi(argv[1]);

	if(number <= 0) {
		std::cerr << "Incorrect ouput size\n";
		return 1;
	}

	std::random_device rd;  									// "Prawdziwa" liczba losowa jako ziarno
	std::default_random_engine generator{rd()};
	std::uniform_int_distribution<> ranVal{1, maximal};
	std::uniform_real_distribution<> ranType{};

	std::cout << number << std::endl;
	for (auto i = 0; i < number; ++i)
	{
		auto x	= ranType(generator);
		if(x < 0.5)
			std::cout << "A " << ranVal(generator) << std::endl;			// 50% chance for add
		else if(x < 0.9)
			std::cout << "D\n";										// 40% chance for delete
		else
			std::cout << "S\n";										// 10% chance for size
	}

	return 0;
}
