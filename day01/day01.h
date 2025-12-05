#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "../input.h"

class Day01 {
private:
	static std::string countCombinationZeros(bool countPasses) {
		int zero_count{ 0 };
		int combination_value{ 50 };

		std::vector<int> combination_movements{
			Input::loadTextLines<int>(
				"day01/p1_input.txt", Input::ParseRule::negateLStart
			)
		};

		for (int i : combination_movements) {
			combination_value += i;
			
			while (combination_value > 99) {
				if (countPasses) { zero_count += 1; }
				combination_value -= 100;
			}
			while (combination_value < 0) {
				if (countPasses) { zero_count += 1; }
				combination_value += 100;
			}
			if (combination_value == 0) { zero_count += 1; }
		}

		return std::to_string(zero_count);
	}

public:
	static std::string solvePart1() { return countCombinationZeros(false); }
	static std::string solvePart2() { return countCombinationZeros(true); }
};