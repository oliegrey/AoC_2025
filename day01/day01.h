#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "../input.h"

class Day01 {
private:
	static int countCombinationZeros(bool countPasses) {
		const int maxRotation{ 100 };

		static std::vector<int> comboDeltas{
			Input::getNegatedLStart("day01/input.txt")
		};

		int zeroCount{ 0 };
		int comboValue{ 50 };

		for (int comboDelta: comboDeltas) {
			comboValue += comboDelta;

			if (countPasses) {
				zeroCount += abs(comboValue / maxRotation);

				if (comboValue <= 0 && comboValue - comboDelta > 0) {
					++zeroCount;
				}
			}

			comboValue %= maxRotation;
			if (comboValue < 0) { comboValue = 100 + comboValue; }
			else if (!countPasses && comboValue == 0) { ++zeroCount; }
		}

		return zeroCount;
	}

public:
	static int solvePart1() { return countCombinationZeros(false); }
	static int solvePart2() { return countCombinationZeros(true); }
};