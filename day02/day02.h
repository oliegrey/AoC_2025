#pragma once

#include <vector>
#include <tuple>
#include <string>

#include "input.h"

class Day02 {
private:
	static int countInvalidIDs() {
		int repeatingIDCount{ 0 };
		std::vector<std::tuple<long long, long long>> inputs{
			Input::getSingleHyphenSplit("day02/input.txt", ',')
		};

		for (std::tuple<long long, long long> range : inputs) {
			for (long long ID{ std::get<0>(range)}; ID <= std::get<1>(range); ++ID) {
				std::string IDString{ std::to_string(ID) };
				if (IDString.length() % 2 != 0) { break; } //cant be repeating if not even

				size_t halfLength{ IDString.length() / 2 };
				bool IDRepeats{ true };
				for (size_t j{ 0 }; j < halfLength; ++j) {
					if (IDString[j] != IDString[j + halfLength]) {
						IDRepeats = false;
						break;
					}
				}
				if (IDRepeats) { 
					++repeatingIDCount; 
				}
			}
		}
		return repeatingIDCount;
	}

public:
	static int solvePart1() { return countInvalidIDs(); }
};