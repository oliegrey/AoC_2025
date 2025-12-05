#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Input {
private:
public:
	template <typename T>
	std::vector<T> loadTextLines(std::string fileName) {
		std::ifstream input_file{ fileName };
		if (!input_file) {
			std::cerr << fileName << " was not loaded";
			return 1;
		}

		T line_value{};
		std::vector<T> output{};
		while (input_file >> line_value) {
			output.push_back(line_value);
		}
		return output;
	}
};