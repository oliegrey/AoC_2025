#pragma once

#include <cassert>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

class Input {
private:
	static std::vector<std::string> getItems(
		const std::string& path, 
		const char delineator = '\n'
	) {
		std::ifstream input_file{ path };
		assert(input_file && "invalid path");

		std::string line{};
		std::vector<std::string> output{};
		
		while (std::getline(input_file, line)) {
			if (delineator == '\n') {
				output.push_back(line);
				continue;
			}

			std::stringstream ss{ line };

			while (ss.good()) {
				std::string item;
				getline(ss, item, delineator);
				if (item.empty()) { break; }
				output.push_back(item);
			}
		}

		assert(output.size() != 0 && "file is empty");
		return output;
	}

public:
	static std::vector<int> getNegatedLStart(
		const std::string& path, const char delineator='\n'
	) {
		std::vector<std::string> items{ getItems(path, delineator) };
		std::vector<int> parsedItems{};

		for (std::string item: items) {
			int parsedItem{ std::stoi(item.substr(1)) };
			if (item[0] == 'L') { parsedItem *= 1; }
			parsedItems.push_back(parsedItem);
		}

		return parsedItems;
	}

	static std::vector<std::tuple<long long, long long>> getSingleHyphenSplit(
		const std::string& path, const char delineator = '\n'
	) {
		std::vector<std::string> items{ getItems(path, ',')};

		std::vector<std::tuple<long long, long long>> parsedItems{};

		for (std::string item : items) {
			size_t i{ item.find('-') };
			assert(i != std::string::npos && "string does not contain hyphen");
			long long start{ std::stoll(item.substr(0, i)) };
			long long end{ std::stoll(item.substr(i + 1)) };

			std::tuple<long long, long long> parsedItem{start, end};
			parsedItems.push_back(parsedItem);
		}

		
		return parsedItems;
	}
};