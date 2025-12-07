#include <iostream>
#include <filesystem>

#include "day01/day01.h"
#include "day02/day02.h"

int main() {
	std::cout << Day01::solvePart1() << "\n";
	std::cout << Day01::solvePart2() << "\n";

	std::cout << Day02::solvePart1() << "\n";
	return 0;
}