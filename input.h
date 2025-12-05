#pragma once

#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

namespace Input {
	enum class ParseRule {
		none,
		negateRStart
	};

	template <typename T>
	std::vector<T> loadTextLines(
		const std::string& path, const ParseRule rule
	) {
		std::ifstream input_file{ path };
		assert(input_file && "invalid path");

		bool negateValue{false};

		T value{};
		std::string line{};
		std::vector<T> output{};
		while (std::getline(input_file, line)) {

			if (!line.empty()) {
				switch (rule) {
				case ParseRule::negateRStart:
						negateValue = (line[0] == 'R');
						line = line.substr(1);
				}

				std::stringstream line_sstream{line};

				if (line_sstream >> value) {
					if (negateValue) { value *= -1; }
					output.push_back(value);
				}
				else { 
					std::cout << "couldnt parse line: " << line << "\n";
				}
			}
				
		}

		assert(output.size() != 0 && "file is empty");
		return output;
	}
};