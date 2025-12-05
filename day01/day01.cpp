#include "day01.h"
#include "../input.h"

#include <fstream>
#include <vector>

std::string Day01::solvePart1() {
	int combination_value{ 50 };

	std::vector<int> combination_movements{ 
		Input::loadTextLines<int>(
			"day01/p1_input.txt", Input::ParseRule::negateRStart
		) 
	};


	return "";
}

std::string Day01::solvePart2() {
	return "";
}